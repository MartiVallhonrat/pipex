/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:20:24 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/20 15:27:32 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	set_first(t_vars *vars, int *i)
{
	if (vars->in_error)
	{
		pipe(vars->end);
		close(vars->end[1]);
		dup2(vars->end[0], STDIN_FILENO);
		close(vars->end[0]);
		(*i)++;
		return ;
	}
	dup2(vars->fd_in, STDIN_FILENO);
	close(vars->fd_in);
}

static void	get_heredoc(char *limiter, t_vars *vars, int *i)
{
	char	*line;

	pipe(vars->end);
	ft_putstr_fd("pipe heredoc>", 0);
	line = get_next_line(0);
	while (ft_strncmp_line(limiter, line, ft_strlen(limiter)) != 0)
	{
		write(vars->end[1], line, ft_strlen(line));
		free(line);
		ft_putstr_fd("pipe heredoc>", 0);
		line = get_next_line(0);
	}
	free(line);
	close(vars->end[1]);
	dup2(vars->end[0], STDIN_FILENO);
	close(vars->end[0]);
	(*i)++;
}

static void	do_child(char *com, char *envp[], t_vars *vars)
{
	pid_t	id;

	pipe(vars->end);
	id = fork();
	if (id == 0)
	{
		close(vars->end[0]);
		dup2(vars->end[1], STDOUT_FILENO);
		close(vars->end[1]);
		exec_com(com, envp, vars);
	}
	else
	{
		close(vars->end[1]);
		dup2(vars->end[0], STDIN_FILENO);
		close(vars->end[0]);
	}
}

static void	set_last(char *com, char *envp[], t_vars *vars)
{
	pid_t	id;
	int		status;

	pipe(vars->end);
	id = fork();
	if (id == 0)
	{
		dup2(vars->fd_out, STDOUT_FILENO);
		close(vars->fd_out);
		close(vars->end[1]);
		exec_com(com, envp, vars);
	}
	else
	{
		wait(&status);
		if (status == 256)
			ft_putstr_fd("ERROR: Command not found\n", 2);
		else if (status != 0)
			ft_putstr_fd("ERROR: Execution error\n", 2);
		if (status != 0)
			exit(1);
	}
}

void	pipex(int argc, char *argv[], char *envp[], t_vars *vars)
{
	int		i;
	int		args;
	int		status;

	i = -1;
	if (vars->here_doc == 0)
		set_first(vars, &i);
	else
		get_heredoc(argv[2], vars, &i);
	while (++i < argc - 4)
		do_child(argv[i + 2], envp, vars);
	args = argc - 4 - vars->here_doc;
	while (args--)
	{
		wait(&status);
		if (status == 256)
			ft_putstr_fd("ERROR: Command not found\n", 2);
		else if (status != 0)
			ft_putstr_fd("ERROR: Execution error\n", 2);
	}
	set_last(argv[argc - 2], envp, vars);
}
