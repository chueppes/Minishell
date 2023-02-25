/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:10:44 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/29 15:21:45 by anna_calvo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src) + 1;
	i = dstsize - 1;
	if (j < dstsize)
		ft_memcpy (dst, src, j);
	else if (dstsize > 0)
		ft_memcpy (dst, src, i);
	dst[i] = '\0';
	return (j - 1);
}
