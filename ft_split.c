/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchati <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 02:43:02 by mchati            #+#    #+#             */
/*   Updated: 2025/10/22 02:45:51 by mchati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

char	*get_next_word(const char **s, char c)
{
	const char	*start;
	int			length;
	char		*word;
	int			i;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	length = *s - start;
	word = malloc(length + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_arry(char **result, int count)
{
	int	j;

	j = 0;
	while (j < count)
	{
		free(result[j]);
		j++;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		word_count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	words = malloc((word_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	while (i < word_count)
	{
		words[i] = get_next_word(&s, c);
		if (!words[i])
		{
			free_arry(words, i);
			return (NULL);
		}
		i++;
	}
	words[word_count] = NULL;
	return (words);
}
