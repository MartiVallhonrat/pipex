/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:03:55 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/13 19:56:58 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_lst
{
	char			*content;
	struct s_lst	*next;
}	t_lst;

char	*get_next_line(int fd);
int		get_n(t_lst **strs, int fd);
int		get_fd_line(char **line, t_lst *str);
int		alloc_rem(t_lst *str, t_lst **strs, int fd);
int		clean_lst_line(t_lst **strs, int fd);
int		find_n(t_lst *node, int call);
int		ft_lstadd_line(t_lst **str, char **buf_str);
int		ft_strlen_line(char *s);
char	*ft_strjoin_line(char *s1, char *s2);
void	free_all_line(t_lst **strs);

#endif
