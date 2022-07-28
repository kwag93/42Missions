/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:06:04 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/10 15:46:44 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define FT_INT_MAX 2147483647
# define FT_INT_MIN 2147483648

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_deque
{
	t_node			*head;
	t_node			*tail;
}					t_deque;

typedef struct		s_oper
{
	int				ra;
	int				rb;
	int				push;
	int				pivot[2];
	int				compare;
}					t_oper;

int					ft_malloc(void *target, size_t size);
t_node				*init_node(int value);
t_deque				*init_deque();
int					isalone(t_deque *deque);
int					isempty(t_deque *deque);
void				push_front(t_deque **deque, int val);
void				push_front_node(t_deque **deque, t_node *node);
t_node				*pop_front(t_deque **deque);
void				push_back(t_deque **deque, int val);
void				push_back_node(t_deque **deque, t_node *node);
t_node				*pop_back(t_deque **deque);
void				swap(t_deque **dq, int ab);
void				ss(t_deque **a, t_deque **b);
void				push(t_deque **fir, t_deque **sec, int *cnt, int ab);
void				rotate(t_deque **dq, int *cnt, int ab);
void				rr(t_deque **a, t_deque **b, int *ra, int *rb);
void				r_rotate(t_deque **dq, int ab);
void				rrr(t_deque **a, t_deque **b);
void				push_swap(t_deque *a, t_deque *b);
int					get_node_data(t_deque *dq, int idx);
int					deque_len(t_deque *dq);
void				a_to_b(t_deque *a, t_deque *b, int cnt);
void				print_queue(t_deque *dq);
void				origin_rotate(t_deque **dq);
void				orgin_push(t_deque **fir, t_deque **sec, int ab);
int					check_dup(t_deque *dq, int value);
void				get_middle_index(t_deque *dq, int size, int (*pivot)[2]);
void				a_to_b(t_deque *a, t_deque *b, int cnt);
void				b_to_a(t_deque *a, t_deque *b, int cnt);
int					check_in_order(t_deque *dq, int cnt);
int					check_reverse_order(t_deque *dq, int cnt);
void				sort_under_five(t_deque *dq, t_deque *dq2, int cnt);
void				sort_reverse_under_five(t_deque *dq, t_deque *dq2, int cnt);
int					get_min(t_deque *dq, int cnt);
int					get_max(t_deque *dq, int cnt);
void				swap_three(t_deque *dq);
void				reverse_swap_three(t_deque *dq);
void				get_balanced_pivots(t_deque *dq, int cnt, int (*pivot)[2]);
int					compare_to_pivot(t_deque *dq, int pivot,
int cnt, int *compare);
void				a_rotate_push(t_deque *a, t_deque *b,
int cnt, t_oper *opers);
void				b_rotate_push(t_deque *a, t_deque *b,
int cnt, t_oper *opers);
void				cnt_rrr(t_deque **a, t_deque **b, int ra, int rb);
int					reverse_compare_to_pivot(t_deque *dq, int pivot,
int cnt, int *compare);
void				swap_three_2(t_deque *dq, int first, int second, int third);
void				reverse_swap_three_2(t_deque *dq,
int first, int second, int third);
void				sort_reverse_swap_three(t_deque *dq);
void				sort_swap_five_2(t_deque *dq,
t_deque *dq2, int *max, int *min);
void				sort_swap_five(t_deque *dq, t_deque *dq2, int cnt);

#endif
