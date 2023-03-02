/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anna_calvo <acalvo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 21:28:02 by anna_calvo        #+#    #+#             */
/*   Updated: 2022/05/31 14:48:50 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (!lst)
		return ;
	if (*lst)
	{
		list = ft_lstlast(*lst);
		list->next = new;
	}
	else
		*lst = new;
}
