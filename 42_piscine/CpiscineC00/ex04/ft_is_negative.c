/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 12:27:29 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/01 09:14:55 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char a;
	char b;

	a = 'P';
	b = 'N';
	if (n >= 0)
	{
		write(1, &a, 1);
	}
	else
	{
		write(1, &b, 1);
	}
}
