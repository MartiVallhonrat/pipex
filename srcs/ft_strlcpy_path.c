/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:14:59 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/14 19:10:57 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_strlcpy_path(char *dst, const char *src, size_t n)
{
	int		count;
	size_t	i;

	count = 0;
	while (src[count] != '\0')
		count++;
	if (n < 1)
		return (count);
	i = 0;
	while (src[i] != '\0' && i < (n - 2))
	{
		dst[i] = src[i];
		i++;
	}
	if (n > 0)
	{
		dst[i++] = '/';
		dst[i] = '\0';
	}
	return (count);
}
