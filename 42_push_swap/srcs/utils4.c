/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:57:13 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 13:58:08 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_middle_index(t_deque *dq, int size, int (*pivot)[2])
{
	int a;
	int b;

	if (size <= 0)
		return ;
	a = get_node_data(dq, size / 2 - 1);
	if (size % 2)
	{
		b = get_node_data(dq, (size / 2) + 1);
		(*pivot)[0] = a > b ? b : a;
		(*pivot)[1] = a > b ? a : b;
	}
	else
	{
		b = get_node_data(dq, size / 2);
		(*pivot)[0] = a > b ? b : a;
		(*pivot)[1] = a > b ? a : b;
	}
}

int		check_dup(t_deque *dq, int value)
{
	t_node *node;

	if (!dq || !(dq->tail))
		return (0);
	node = dq->tail;
	while (node)
	{
		if (node->data == value)
			return (1);
		node = node->prev;
	}
	return (0);
}

int		check_in_order(t_deque *dq, int cnt)
{
	t_node	*node;
	int		idx;

	idx = 1;
	node = dq->tail->prev;
	while (node && idx++ < cnt)
	{
		if (node->data < node->next->data)
			return (0);
		node = node->prev;
	}
	return (1);
}

int		check_reverse_order(t_deque *dq, int cnt)
{
	t_node	*node;
	int		idx;

	idx = 1;
	if (!dq->tail)
		return (1);
	node = dq->tail->prev;
	while (node && idx++ < cnt)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->prev;
	}
	return (1);
}
