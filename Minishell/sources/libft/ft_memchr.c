/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:22:48 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/23 13:57:18 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		j;

	str = (const char *)s;
	j = 0;
	while (j < n)
	{
		if (str[j] == (char)c)
			return ((void *)str + j);
		j++;
	}
	return (0);
}
