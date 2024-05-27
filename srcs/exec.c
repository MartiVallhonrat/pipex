/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:36:35 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/14 16:02:07 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_com(char *com, char *envp[], t_vars *vars)
{
	int		i;
	char	**args;
	char	*program;

	args = ft_split(com, ' ');
	i = -1;
	while (vars->paths[++i])
	{
		program = ft_strjoin(vars->paths[i], args[0]);
		if (access(program, X_OK) == 0)
			break ;
	}
	if (!(vars->paths[i]))
		throw_error(vars);
	if (execve(program, args, envp) < 0)
		throw_error(vars);
}
