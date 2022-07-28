/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 14:38:07 by hyunyoo           #+#    #+#             */
/*   Updated: 2021/06/10 15:35:06 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_malloc(void *target, size_t size)
{
	void	**pt;

	pt = (void **)target;
	*pt = malloc(size);
	if (*pt == 0)
		return (0);
	return (1);
}
