/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:42:47 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 15:35:10 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node		*init_node(int value)
{
	t_node	*new_node;

	if (!ft_malloc(&new_node, sizeof(t_node)))
		return (NULL);
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_deque		*init_deque(void)
{
	t_deque	*new_deque;

	if (!ft_malloc(&new_deque, sizeof(t_deque)))
		return (NULL);
	new_deque->head = NULL;
	new_deque->tail = NULL;
	return (new_deque);
}

int			isempty(t_deque *deque)
{
	if (!deque->head && !deque->tail)
		return (1);
	else
		return (0);
}

void		push_front(t_deque **deque, int val)
{
	t_node	*new_node;

	if (check_dup(*deque, val))
	{
		ft_putstr_fd("Error\n", 1);
		exit(0);
	}
	new_node = init_node(val);
	if (isempty((*deque)))
		(*deque)->tail = new_node;
	else
		(*deque)->head->prev = new_node;
	new_node->next = (*deque)->head;
	new_node->prev = NULL;
	(*deque)->head = new_node;
}

void		push_front_node(t_deque **deque, t_node *node)
{
	if (isempty(*deque))
		(*deque)->tail = node;
	else
		(*deque)->head->prev = node;
	node->next = (*deque)->head;
	node->prev = NULL;
	(*deque)->head = node;
}
