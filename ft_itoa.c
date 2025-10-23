/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchati <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:37:55 by mchati            #+#    #+#             */
/*   Updated: 2025/10/22 15:11:31 by mchati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		len;

	num = n;
	len = count_digits(n);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (num == 0)
		return (res[0] = '0', res);
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
