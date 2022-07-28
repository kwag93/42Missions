/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivots.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 13:55:05 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 15:35:12 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		get_node_data(t_deque *dq, int idx)
{
	t_node	*node;
	int		cnt;

	node = dq->tail;
	cnt = 0;
	while (node && cnt < idx)
	{
		node = node->prev;
		cnt++;
	}
	return (node->data);
}

int		compare_to_pivot(t_deque *dq, int pivot, int cnt, int *compare)
{
	t_node *node;

	node = dq->tail;
	while (node && cnt--)
	{
		if (node->data < pivot)
		{
			*compare = 0;
			return (0);
		}
		node = node->prev;
		(*compare)++;
	}
	return (1);
}

void	ft_swap(int **arr, int idx)
{
	int temp;

	temp = (*arr)[idx + 1];
	(*arr)[idx + 1] = (*arr)[idx];
	(*arr)[idx] = temp;
}

void	get_balanced_pivots(t_deque *dq, int cnt, int (*pivot)[2])
{
	int *arr;
	int idx;
	int idx2;
	int temp;

	ft_malloc(&arr, sizeof(int) * cnt);
	idx = 0;
	temp = cnt;
	while (temp >= 1)
		arr[idx++] = get_node_data(dq, cnt - (temp--));
	idx = cnt - 1;
	while (idx > 0)
	{
		idx2 = 0;
		while (idx2 < idx)
		{
			if (arr[idx2] > arr[idx2 + 1])
				ft_swap(&arr, idx2);
			idx2++;
		}
		idx--;
	}
	(*pivot)[0] = arr[cnt / 3];
	(*pivot)[1] = arr[cnt * 2 / 3];
	free(arr);
}

int		reverse_compare_to_pivot(t_deque *dq, int pivot, int cnt, int *compare)
{
	t_node *node;

	node = dq->tail;
	while (node && cnt--)
	{
		if (node->data >= pivot)
		{
			*compare = 0;
			return (0);
		}
		node = node->prev;
		(*compare)++;
	}
	return (1);
}
