/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 15:34:01 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/15 14:49:39 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	start_push(t_deque **dq, t_deque **dq2, char **argv)
{
	char	*chr;

	chr = NULL;
	while (*argv[1])
	{
		chr = ft_strchr(argv[1], ' ');
		if (*chr)
			*chr++ = '\0';
		push_front(dq, ft_atoi(argv[1]));
		argv[1] = chr;
	}
	if (deque_len(*dq) <= 5)
		sort_under_five(*dq, *dq2, deque_len(*dq));
	a_to_b(*dq, *dq2, deque_len(*dq));
}

void	double_free(t_deque *dq)
{
	t_node	*node;
	t_node	*tmp;

	node = dq->tail;
	while (node)
	{
		tmp = node->prev;
		free(node);
		node = tmp;
	}
	free(dq);
}

int		main(int argc, char **argv)
{
	t_deque	*deque;
	t_deque	*deque2;
	int		idx;

	if (argc < 2)
		return (0);
	deque = init_deque();
	deque2 = init_deque();
	if (argc == 2)
		start_push(&deque, &deque2, argv);
	else
	{
		idx = 1;
		while (argv[idx])
			push_front(&deque, ft_atoi(argv[idx++]));
		if (deque_len(deque) <= 5)
			sort_under_five(deque, deque2, deque_len(deque));
		else
			a_to_b(deque, deque2, deque_len(deque));
	}
	double_free(deque);
	double_free(deque2);
	return (0);
}
