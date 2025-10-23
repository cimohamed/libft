/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchati <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 08:42:05 by mchati            #+#    #+#             */
/*   Updated: 2025/10/18 09:01:36 by mchati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char )c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((unsigned char )c == '\0')
		return ((char *)s + i);
	return (NULL);
}
