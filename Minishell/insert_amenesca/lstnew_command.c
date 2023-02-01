/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:16:41 by acalvo4           #+#    #+#             */
/*   Updated: 2022/05/31 14:57:05 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

t_commands	*lstnew_command(char *content)
{
	t_commands	*comm;

	comm = malloc(sizeof(t_commands));
	if (!comm)
		return (NULL);
	comm->cmd = ft_strdup((const char *) content);
	comm->next = NULL;
	return (comm);
}
