/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:35:41 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/14 19:13:43 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	is_heredoc(int argc, char *argv[], t_vars *vars)
{
	vars->here_doc = 0;
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		vars->here_doc = 1;
		vars->fd_out = open(argv[argc - 1], O_CREAT
				| O_WRONLY | O_APPEND, 0664);
	}
	else
	{
		vars->fd_in = open(argv[1], O_RDONLY);
		vars->fd_out = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0664);
	}
}

static void	check_input(int argc, char *argv[], t_vars *vars)
{
	if (argc < 5)
	{
		ft_putstr_fd("ERROR: Minimum num of arguments is 4\n", 2);
		exit(1);
	}
	is_heredoc(argc, argv, vars);
	if (vars->fd_out < 0)
		throw_error(vars);
	vars->in_error = 0;
	if ((vars->fd_in < 0 || read(vars->fd_in, 0, 0) < 0
			|| write(vars->fd_out, 0, 0) < 0) && !vars->here_doc)
	{
		perror("ERROR");
		vars->in_error = 1;
	}
}

static void	parse_comms(char *envp[], t_vars *vars)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmpl(envp[i], "PATH", 3) == 0)
		{
			vars->paths = ft_split_path(envp[i], ':');
			return ;
		}
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_vars	vars;

	vars.paths = NULL;
	check_input(argc, argv, &vars);
	parse_comms(envp, &vars);
	pipex(argc, argv, envp, &vars);
	free_paths(&vars);
	return (0);
}
