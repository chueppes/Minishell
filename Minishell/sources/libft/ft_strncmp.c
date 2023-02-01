/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:06:21 by acalvo4           #+#    #+#             */
/*   Updated: 2023/02/01 16:57:07 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (-1);
	while (*s1 != '\0' && *s2 != '\0' && n > 0)
	{	
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}


// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*str1;
// 	unsigned char	*str2;

// 	str1 = (unsigned char *)s1;
// 	str2 = (unsigned char *)s2;
// 	i = 0;
// 	if (n == 0)
// 		return (0);
// 	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
// 		return ((int)str1[i] - (int)str2[i]);
// 	while (i <= ft_strlen(s1) && i <= ft_strlen(s2) && n > 0)
// 	{
// 		if (str1[i] != str2[i])
// 			return ((int)str1[i] - (int)str2[i]);
// 		i++;
// 		n--;
// 	}
// 	return (0);
// }
