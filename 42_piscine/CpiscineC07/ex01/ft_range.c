/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:59:35 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/17 10:39:34 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *arr;
	int i;
	int len;

	i = 0;
	len = max - min;
	arr = (int *)malloc(sizeof(int) * len);
	if (min >= max)
		return (0);
	while (i < len)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
