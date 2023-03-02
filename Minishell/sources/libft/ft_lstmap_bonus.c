/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:32:29 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/31 12:48:01 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list1;
	t_list	*list2;

	list2 = 0;
	if (!lst || !del || !f)
		return (NULL);
	while (lst)
	{
		list1 = ft_lstnew(f(lst->content));
		if (!list1)
		{
			ft_lstclear(&list2, del);
			return (list2);
		}
		ft_lstadd_back(&list2, list1);
		lst = lst->next;
	}
	return (list2);
}
