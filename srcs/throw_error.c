/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:44:30 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/14 13:38:12 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_paths(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->paths[i])
	{
		free(vars->paths[i]);
		i++;
	}
	free(vars->paths);
	vars->paths = NULL;
}

void	throw_error(t_vars *vars)
{
	if (vars->paths)
		free_paths(vars);
	perror("ERROR");
	exit(1);
}
