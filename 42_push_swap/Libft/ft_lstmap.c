/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:24:36 by bkwag             #+#    #+#             */
/*   Updated: 2020/08/06 09:47:38 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ans;
	t_list *tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	ans = NULL;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&ans, del);
			return (NULL);
		}
		ft_lstadd_back(&ans, tmp);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (ans);
}
