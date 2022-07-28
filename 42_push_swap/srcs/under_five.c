/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:27:53 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/15 14:46:19 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_three(t_deque *dq)
{
	int first;
	int second;
	int third;

	first = get_node_data(dq, 0);
	second = get_node_data(dq, 1);
	third = get_node_data(dq, 2);
	if (first > second && first < third)
		swap(&dq, 0);
	else if (first > second && second > third)
	{
		swap(&dq, 0);
		rotate(&dq, NULL, 0);
		swap(&dq, 0);
		r_rotate(&dq, 0);
		swap(&dq, 0);
	}
	else
		swap_three_2(dq, first, second, third);
}

void	reverse_swap_three(t_deque *dq)
{
	int first;
	int second;
	int third;

	first = get_node_data(dq, 0);
	second = get_node_data(dq, 1);
	third = get_node_data(dq, 2);
	if (first > second && first < third)
	{
		rotate(&dq, NULL, 1);
		swap(&dq, 1);
		r_rotate(&dq, 1);
		swap(&dq, 1);
	}
	else if (first < second && second < third)
	{
		swap(&dq, 1);
		rotate(&dq, NULL, 1);
		swap(&dq, 1);
		r_rotate(&dq, 1);
		swap(&dq, 1);
	}
	else
		reverse_swap_three_2(dq, first, second, third);
}

void	sort_swap_three(t_deque *dq)
{
	int first;
	int second;
	int third;

	first = get_node_data(dq, 0);
	second = get_node_data(dq, 1);
	third = get_node_data(dq, 2);
	if (first > second && first < third)
		swap(&dq, 0);
	else if (first > second && second > third)
	{
		swap(&dq, 0);
		r_rotate(&dq, 0);
	}
	else if (second < third && third < first)
		rotate(&dq, NULL, 0);
	else if (first < third && third < second)
	{
		swap(&dq, 0);
		rotate(&dq, NULL, 0);
	}
	else if (third < first && first < second)
		r_rotate(&dq, 0);
}

void	sort_under_five(t_deque *dq, t_deque *dq2, int cnt)
{
	int i;
	int max;
	int min;

	if (check_in_order(dq, cnt))
		return ;
	if (cnt == 1)
		return ;
	if (cnt == 2)
	{
		if (cnt > 1 && get_node_data(dq, 0) > get_node_data(dq, 1))
			swap(&dq, 0);
		return ;
	}
	else if (cnt == 3)
		sort_swap_three(dq);
	else if (cnt <= 5)
		sort_swap_five(dq, dq2, cnt);
}

void	sort_reverse_under_five(t_deque *dq, t_deque *dq2, int cnt)
{
	int i;
	int max;
	int min;

	if (cnt == 2)
	{
		if (cnt > 1 && get_node_data(dq, 0) < get_node_data(dq, 1))
			swap(&dq, 1);
		return ;
	}
	else if (cnt == 3)
		sort_reverse_swap_three(dq);
}
