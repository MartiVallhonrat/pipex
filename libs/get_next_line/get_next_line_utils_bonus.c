/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:36:39 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/13 19:56:45 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_n(t_lst *node, int call)
{
	char	*content;
	int		counter;

	counter = 0;
	if (node == NULL)
		return (0);
	while (node)
	{
		content = node->content;
		while (*content != '\0' && *content != '\n')
		{
			content++;
			counter++;
		}
		if (*content == '\n')
			return (++counter);
		node = node->next;
	}
	if (call == 2)
		return (counter);
	return (0);
}

int	ft_lstadd_line(t_lst **str, char **buf_str)
{
	t_lst	*new;
	t_lst	*temp;

	new = (t_lst *) malloc(sizeof (t_list));
	if (!new)
	{
		free(*buf_str);
		return (0);
	}
	new->content = *buf_str;
	new->next = NULL;
	if (*str == NULL)
		*str = new;
	else
	{
		temp = *str;
		while ((*str)->next != NULL)
			*str = (*str)->next;
		(*str)->next = new;
		*str = temp;
	}
	return (1);
}

int	ft_strlen_line(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strjoin_line(char *s1, char *s2)
{
	int		i;
	int		len1;
	char	*str;

	len1 = ft_strlen_line(s1);
	str = (char *) malloc (len1 + ft_strlen_line(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	i = -1;
	while (s1 != NULL && s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
		str[len1++] = s2[i];
	if (s1)
		free(s1);
	str[len1] = '\0';
	return (str);
}

void	free_all_line(t_lst **str)
{
	t_lst	*temp;
	t_lst	*head;

	head = *str;
	while (head)
	{
		temp = head->next;
		free(head->content);
		free(head);
		head = temp;
	}
	*str = NULL;
}
