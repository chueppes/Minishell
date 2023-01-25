/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:49:53 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/26 12:16:41 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	lend;
	size_t	out;

	i = 0;
	lend = ft_strlen(dst);
	if (dstsize > lend)
		out = ft_strlen(src) + lend;
	else
		out = ft_strlen(src) + dstsize;
	while (src[i] != '\0' && lend + 1 < dstsize)
	{
		dst[lend] = src[i];
		i++;
		lend++;
	}
	dst[lend] = '\0';
	return (out);
}
