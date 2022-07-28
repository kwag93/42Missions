/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:30:18 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 15:35:15 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_min(t_deque *dq, int cnt)
{
	t_node	*node;
	int		idx;
	int		min;

	node = dq->tail;
	min = dq->tail->data;
	idx = 0;
	while (node && idx < cnt)
	{
		min = min < node->data ? min : node->data;
		node = node->prev;
		cnt++;
	}
	return (min);
}

int		get_max(t_deque *dq, int cnt)
{
	t_node	*node;
	int		idx;
	int		max;

	node = dq->tail;
	max = dq->tail->data;
	idx = 0;
	while (node && idx < cnt)
	{
		max = max > node->data ? max : node->data;
		node = node->prev;
		cnt++;
	}
	return (max);
}

int		deque_len(t_deque *dq)
{
	t_node	*idx;
	int		cnt;

	idx = dq->head;
	cnt = 0;
	while (idx)
	{
		idx = idx->next;
		cnt++;
	}
	return (cnt);
}
