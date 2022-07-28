/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_factorial.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:47:33 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/09 10:10:18 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_interative_factorial(int nb)
{
	int n;

	n = 1;
    if (nb < 0)
        return (0);
	if (nb == 0)
		return (1);
	while (nb)
	{
		n *= nb;
		nb--;
	}
	return (n);
}
