/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:37:04 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 15:35:24 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_deque **dq, int *cnt, int ab)
{
	t_node *temp;

	temp = pop_back(dq);
	if (!temp)
		return ;
	push_front_node(dq, temp);
	if (ab)
		ft_putstr_fd("rb\n", 1);
	else
		ft_putstr_fd("ra\n", 1);
	if (cnt)
		(*cnt)++;
}

void	origin_rotate(t_deque **dq)
{
	t_node *temp;

	temp = pop_back(dq);
	if (!temp)
		return ;
	push_front_node(dq, temp);
}

void	push(t_deque **fir, t_deque **sec, int *cnt, int ab)
{
	t_node *temp;

	temp = pop_back(fir);
	if (!temp)
		return ;
	push_back_node(sec, temp);
	if (ab)
		ft_putstr_fd("pb\n", 1);
	else
		ft_putstr_fd("pa\n", 1);
	if (cnt)
		(*cnt)++;
}

void	orgin_push(t_deque **fir, t_deque **sec, int ab)
{
	t_node *temp;

	temp = pop_back(fir);
	if (!temp)
		return ;
	push_back_node(sec, temp);
	if (ab)
		ft_putstr_fd("pb\n", 1);
	else
		ft_putstr_fd("pa\n", 1);
}

void	cnt_rrr(t_deque **a, t_deque **b, int ra, int rb)
{
	int tmp;

	tmp = ra < rb ? ra : rb;
	while (tmp--)
		rrr(a, b);
	tmp = ra < rb ? ra : rb;
	while (ra - (tmp++))
		r_rotate(a, 0);
	tmp = ra < rb ? ra : rb;
	while (rb - (tmp++))
		r_rotate(b, 1);
}
