/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 11:44:15 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/22 16:05:14 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newnode;

	if (!(newnode = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
