/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:29:57 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/29 20:38:07 by anna_calvo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	dlen;
	size_t	size;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	dlen = slen - start;
	size = 0;
	if (start > slen)
		return (ft_strdup(""));
	if (start + len > slen)
		size = dlen;
	else
		size = len;
	str = ft_calloc((size + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, size + 1);
	return (str);
}
