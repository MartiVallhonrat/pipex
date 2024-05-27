/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvallhon <mvallhon@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:09:34 by mvallhon          #+#    #+#             */
/*   Updated: 2024/03/14 16:01:14 by mvallhon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	int		trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static size_t	next_word(char const *str, size_t *i, char c)
{
	size_t	size;

	while (str[*i] && str[*i] == c)
		*i += 1;
	size = 0;
	while (str[*i + size] && str[*i + size] != c)
		size++;
	return (size);
}

static void	free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	put_word(char *strs[], char const *s, char c, size_t words)
{
	size_t	word_size;
	size_t	words_count;
	size_t	i;

	i = 0;
	words_count = 0;
	while (words_count < words)
	{
		word_size = next_word(s, &i, c);
		strs[words_count] = ft_calloc(sizeof (char), word_size + 2);
		if (!strs[words_count])
		{
			free_all(strs);
			exit (1);
		}
		ft_strlcpy_path(strs[words_count++], &s[i], word_size + 2);
		i += word_size;
	}
}

char	**ft_split_path(char const *s, char c)
{
	char	**strs;
	size_t	words;

	s += 5;
	words = count_words(s, c);
	strs = ft_calloc(sizeof (char *), words + 1);
	if (!strs)
		return (NULL);
	put_word(strs, s, c, words);
	return (strs);
}
