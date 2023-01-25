/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:50:14 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/24 14:18:22 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	strlen;
	size_t	p2;

	p2 = ft_strlen(s1);
	strlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(strlen);
	ft_strlcpy(&str[0], s1, ft_strlen(s1) + 1);
	ft_strlcpy(&str[p2], s2, ft_strlen(s2) + 1);
	return (str);
}
