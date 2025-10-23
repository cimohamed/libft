/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchati <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 04:29:55 by mchati            #+#    #+#             */
/*   Updated: 2025/10/22 06:22:02 by mchati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	en;
	size_t	len;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	st = 0;
	while (s1[st] && isinset(s1[st], set))
		st++;
	en = ft_strlen(s1);
	while (en > st && isinset(s1[en - 1], set))
		en--;
	len = en - st;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + st, len + 1);
	return (res);
}
