/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:14:18 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/17 15:33:43 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int len;
	int *arr;

	i = 0;
	len = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if (!(arr = (int *)malloc(sizeof(int) * len)))
	{
		*range = NULL;
		return (-1);
	}
	*range = arr;
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (i);
}
