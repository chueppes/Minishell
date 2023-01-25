/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:36:29 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/18 11:27:52 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tdest;
	const char	*tsrc;

	tsrc = (char *)src;
	tdest = (char *)dest;
	if (tdest == tsrc || n == 0)
		return (dest);
	while (n-- > 0)
	{
		tdest[n] = tsrc[n];
	}
	return (dest);
}
