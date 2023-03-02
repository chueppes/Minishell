/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:53:00 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/30 14:07:42 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size( long n);

char	*ft_itoa(int n)
{
	char	*str;
	int		s;
	long	nlong;

	nlong = n;
	s = size(n);
	str = ft_calloc((s + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (nlong < 0)
	{
		str[0] = '-';
		nlong *= -1;
	}
	if (nlong == 0)
		str[0] = '0';
	str[s--] = '\0';
	while (nlong)
	{
		str[s] = nlong % 10 + '0';
		s--;
		nlong = nlong / 10;
	}
	return (str);
}

static size_t	size(long n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
