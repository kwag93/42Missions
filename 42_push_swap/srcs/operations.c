/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:43:35 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 13:59:32 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_deque **dq, int ab)
{
	t_node *temp;

	if (isempty(*dq) || isalone(*dq))
		return ;
	temp = (*dq)->tail;
	if ((*dq)->head == temp->prev)
		(*dq)->head = temp;
	(*dq)->tail = temp->prev;
	temp->next = (*dq)->tail;
	temp->prev = (*dq)->tail->prev;
	if (temp->prev)
		temp->prev->next = temp;
	(*dq)->tail->next = NULL;
	(*dq)->tail->prev = temp;
	if (ab == 1)
		ft_putstr_fd("sb\n", 1);
	else if (ab == 0)
		ft_putstr_fd("sa\n", 1);
}

void	ss(t_deque **a, t_deque **b)
{
	swap(a, -1);
	swap(b, -1);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_deque **a, t_deque **b, int *ra, int *rb)
{
	origin_rotate(a);
	origin_rotate(b);
	(*ra)++;
	(*rb)++;
	ft_putstr_fd("rr\n", 1);
}

void	r_rotate(t_deque **dq, int ab)
{
	t_node *temp;

	temp = pop_front(dq);
	if (!temp)
		return ;
	push_back_node(dq, temp);
	if (ab == 1)
		ft_putstr_fd("rrb\n", 1);
	else if (ab == 0)
		ft_putstr_fd("rra\n", 1);
}

void	rrr(t_deque **a, t_deque **b)
{
	r_rotate(a, -1);
	r_rotate(b, -1);
	ft_putstr_fd("rrr\n", 1);
}
