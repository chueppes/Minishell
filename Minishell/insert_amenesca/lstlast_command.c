/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anna_calvo <acalvo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:39:16 by anna_calvo        #+#    #+#             */
/*   Updated: 2022/05/31 12:46:47 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

t_commands	*lstlast_command(t_commands *lst)
{
	if (!lst)
		return (NULL);
	if (lst == NULL)
		return (0);
	while (lst ->next != NULL)
		lst = lst->next;
	return (lst);
}
