/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:13:04 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/23 15:25:57 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	slen;
	char	*s2;
	size_t	i;

	i = 0;
	slen = ft_strlen(s1);
	s2 = malloc((slen + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (i <= slen)
	{
		s2[i] = s1[i];
		i++;
	}
	return ((char *)s2);
}
