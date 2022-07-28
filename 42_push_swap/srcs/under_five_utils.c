/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:22:10 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 15:40:42 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_three_2(t_deque *dq, int first, int second, int third)
{
	if (second < third && third < first)
	{
		swap(&dq, 0);
		rotate(&dq, NULL, 0);
		swap(&dq, 0);
		r_rotate(&dq, 0);
	}
	else if (first < third && third < second)
	{
		rotate(&dq, NULL, 0);
		swap(&dq, 0);
		r_rotate(&dq, 0);
	}
	else if (third < first && first < second)
	{
		rotate(&dq, NULL, 0);
		swap(&dq, 0);
		r_rotate(&dq, 0);
		swap(&dq, 0);
	}
}

void	reverse_swap_three_2(t_deque *dq, int first, int second, int third)
{
	if (second < third && third < first)
	{
		rotate(&dq, NULL, 1);
		swap(&dq, 1);
		r_rotate(&dq, 1);
	}
	else if (first < third && third < second)
	{
		swap(&dq, 1);
		rotate(&dq, NULL, 1);
		swap(&dq, 1);
		r_rotate(&dq, 1);
	}
	else if (third < first && first < second)
		swap(&dq, 1);
}

void	sort_reverse_swap_three(t_deque *dq)
{
	int first;
	int second;
	int third;

	first = get_node_data(dq, 0);
	second = get_node_data(dq, 1);
	third = get_node_data(dq, 2);
	if (first > second && first < third)
		r_rotate(&dq, 1);
	else if (first < second && second < third)
	{
		swap(&dq, 1);
		r_rotate(&dq, 1);
	}
	else if (second < third && third < first)
	{
		swap(&dq, 1);
		rotate(&dq, NULL, 1);
	}
	else if (first < third && third < second)
		rotate(&dq, NULL, 1);
	else if (third < first && first < second)
		swap(&dq, 1);
}

void	sort_swap_five_2(t_deque *dq, t_deque *dq2, int *max, int *min)
{
	if (dq2->tail->data > *min && dq2->tail->data < *max)
	{
		if (dq2->tail->data < dq->tail->data)
		{
			while (dq2->tail->data < dq->head->data)
				r_rotate(&dq, 0);
		}
		else
		{
			while (dq2->tail->data > dq->tail->data)
				rotate(&dq, NULL, 0);
		}
		push(&dq2, &dq, NULL, 0);
	}
	else
	{
		while (*max != dq->head->data)
			rotate(&dq, NULL, 0);
		push(&dq2, &dq, NULL, 0);
	}
	if (*max < dq->tail->data)
		*max = dq->tail->data;
	else if (*min > dq->tail->data)
		*min = dq->tail->data;
}

void	sort_swap_five(t_deque *dq, t_deque *dq2, int cnt)
{
	int i;
	int max;
	int min;

	push(&dq, &dq2, NULL, 1);
	push(&dq, &dq2, NULL, 1);
	sort_under_five(dq, dq2, cnt - 2);
	i = 0;
	min = get_min(dq, cnt - deque_len(dq2));
	max = get_max(dq, cnt - deque_len(dq2));
	while (cnt - (i++) > cnt - 2)
		sort_swap_five_2(dq, dq2, &max, &min);
	if (deque_len(dq) == 5 && dq->tail->data > dq->tail->prev->data)
		rotate(&dq, NULL, 0);
	else
	{
		while (min != dq->tail->data)
			r_rotate(&dq, 0);
	}
}
