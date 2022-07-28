/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:30:42 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 15:33:41 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_opers(t_oper *opers)
{
	opers->ra = 0;
	opers->rb = 0;
	opers->push = 0;
	opers->compare = 0;
	opers->pivot[0] = 0;
	opers->pivot[1] = 0;
}

void	a_rotate_push(t_deque *a, t_deque *b, int cnt, t_oper *opers)
{
	int rrotate;

	rrotate = 0;
	while (cnt--)
	{
		if (compare_to_pivot(a, opers->pivot[1], cnt + 1, &(opers->compare)))
			break ;
		if (a->tail->data >= opers->pivot[1])
		{
			if (rrotate && !(rrotate = 0))
				rr(&a, &b, &(opers->ra), &(opers->rb));
			else
				rotate(&a, &(opers->ra), 0);
		}
		else
		{
			if (rrotate && !(rrotate = 0))
				rotate(&b, &(opers->rb), 1);
			push(&a, &b, &(opers->push), 1);
			if (b->tail->data >= opers->pivot[0])
				rrotate = 1;
		}
	}
	if (rrotate)
		rotate(&b, &opers->rb, 1);
}

void	b_rotate_push(t_deque *a, t_deque *b, int cnt, t_oper *opers)
{
	while (cnt--)
	{
		if (reverse_compare_to_pivot(b, opers->pivot[0],
		cnt + 1, &(opers->compare)))
			break ;
		if (b->tail->data < opers->pivot[0])
			rotate(&b, &(opers->rb), 1);
		else
		{
			push(&b, &a, &(opers->push), 0);
			if (a->tail && a->tail->data < opers->pivot[1])
				rotate(&a, &(opers->ra), 0);
		}
	}
}

void	a_to_b(t_deque *a, t_deque *b, int cnt)
{
	t_oper opers;

	init_opers(&opers);
	if (check_in_order(a, cnt))
		return ;
	if (cnt < 3)
	{
		if (cnt > 1 && get_node_data(a, 0) > get_node_data(a, 1))
			swap(&a, 0);
		return ;
	}
	get_balanced_pivots(a, cnt, &(opers.pivot));
	a_rotate_push(a, b, cnt, &opers);
	cnt_rrr(&a, &b, opers.ra, opers.rb);
	a_to_b(a, b, opers.ra + opers.compare);
	b_to_a(a, b, opers.rb);
	b_to_a(a, b, opers.push - opers.rb);
}

void	b_to_a(t_deque *a, t_deque *b, int cnt)
{
	t_oper opers;

	init_opers(&opers);
	if (check_reverse_order(b, cnt))
	{
		while (b->tail && cnt--)
			push(&b, &a, NULL, 0);
		return ;
	}
	if (cnt < 3)
	{
		if (cnt > 1 && get_node_data(b, 0) < get_node_data(b, 1))
			swap(&b, 1);
		while (b->tail && cnt--)
			push(&b, &a, NULL, 0);
		return ;
	}
	get_balanced_pivots(b, cnt, &opers.pivot);
	b_rotate_push(a, b, cnt, &opers);
	a_to_b(a, b, opers.push - opers.ra);
	cnt_rrr(&a, &b, opers.ra, opers.rb);
	a_to_b(a, b, opers.ra);
	b_to_a(a, b, opers.rb + opers.compare);
}
