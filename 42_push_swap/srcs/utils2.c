/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:42:37 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 13:58:50 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			isalone(t_deque *deque)
{
	t_node	*temp;
	int		cnt;

	cnt = 0;
	temp = deque->head;
	while (temp)
	{
		temp = temp->next;
		cnt++;
	}
	return (cnt == 1);
}

t_node		*pop_front(t_deque **deque)
{
	t_node *result;

	if (isempty(*deque))
		return (NULL);
	result = (*deque)->head;
	(*deque)->head = result->next;
	if (!(*deque)->head)
		(*deque)->tail = NULL;
	else
		(*deque)->head->prev = NULL;
	result->next = NULL;
	return (result);
}

void		push_back(t_deque **deque, int val)
{
	t_node	*new_node;

	new_node = init_node(val);
	if (isempty(*deque))
		(*deque)->head = new_node;
	else
		(*deque)->tail->next = new_node;
	new_node->prev = (*deque)->tail;
	new_node->next = NULL;
	(*deque)->tail = new_node;
}

void		push_back_node(t_deque **deque, t_node *node)
{
	if (isempty(*deque))
		(*deque)->head = node;
	else
		(*deque)->tail->next = node;
	node->prev = (*deque)->tail;
	node->next = NULL;
	(*deque)->tail = node;
}

t_node		*pop_back(t_deque **deque)
{
	t_node *result;

	if (isempty(*deque))
		return (NULL);
	result = (*deque)->tail;
	(*deque)->tail = result->prev;
	if (!(*deque)->tail)
		(*deque)->head = NULL;
	else
		(*deque)->tail->next = NULL;
	result->prev = NULL;
	return (result);
}
