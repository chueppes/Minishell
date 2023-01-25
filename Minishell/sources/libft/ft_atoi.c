/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:43:48 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/23 15:39:46 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	over(int j);

int	ft_atoi(const char *str)
{
	size_t	i;
	long	aux;
	long	number;
	int		j;

	aux = 0;
	i = 0;
	j = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = aux;
		aux = (aux * 10) + (str[i] - '0');
		if (number > aux)
			return (over(j));
		i++;
	}
	return (aux * j);
}

static int	over(int j)
{
	if (j == -1)
		return (0);
	else
		return (-1);
}
