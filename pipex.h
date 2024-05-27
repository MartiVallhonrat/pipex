/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:34:01 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/20 15:30:48 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include "libs/libft/libft.h"
# include "libs/get_next_line/get_next_line.h"

typedef struct s_vars
{
	int		here_doc;
	int		fd_in;
	int		fd_out;
	char	**paths;
	int		end[2];
	int		in_error;
}	t_vars;

int		ft_strcmpl(char *s1, char *s2, int len);
int		ft_strncmp_line(char *s1, char *s2, int n);
char	**ft_split_path(char const *s, char c);
int		ft_strlcpy_path(char *dst, const char *src, size_t n);
void	free_paths(t_vars *vars);
void	throw_error(t_vars *vars);
void	pipex(int argc, char *argv[], char *envp[], t_vars *vars);
void	exec_com(char *com, char *envp[], t_vars *vars);
void	do_dup_first(t_vars *vars);
void	do_dup_middle(int i, t_vars *vars);
void	do_dup_last(t_vars *vars);

#endif
