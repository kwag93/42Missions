/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:02:34 by bkwag             #+#    #+#             */
/*   Updated: 2020/08/05 17:58:31 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *curr;
	t_list *next;

	curr = *lst;
	while (curr)
	{
		next = curr->next;
		ft_lstdelone(curr, del);
		curr = next;
	}
	*lst = NULL;
}
