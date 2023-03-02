/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:46:04 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/24 11:40:26 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*tdest;
	const char	*tsrc;
	size_t		j;

	tsrc = (char *)src;
	tdest = (char *)dest;
	j = 0;
	if (tsrc > tdest && (tsrc - tdest) < (int)len)
	{
		while (j < len)
		{
			tdest[j] = tsrc[j];
			j++;
		}
		return (dest);
	}
	ft_memcpy(dest, src, len);
	return (dest);
}
