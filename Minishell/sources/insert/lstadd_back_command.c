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

#include "../.././includes/minishell.h"

void	lstadd_back_command(t_commands **lst, t_commands *new)
{
	t_commands	*list;

	if (!lst)
		return ;
	if (*lst)
	{
		list = lstlast_command(*lst);
		list->next = new;
	}
	else
		*lst = new;
}
