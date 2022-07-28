/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 12:29:31 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/01 09:17:39 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char a[3];

	a[0] = '0';
	while (a[0] <= '7')
	{
		a[1] = a[0] + 1;
		while (a[1] <= '8')
		{
			a[2] = a[1] + 1;
			while (a[2] <= '9')
			{
				ft_putchar(a[0]);
				ft_putchar(a[1]);
				ft_putchar(a[2]);
				if (a[0] == '7' && a[1] == '8' && a[2] == '9')
					break ;
				ft_putchar(',');
				ft_putchar(' ');
				a[2]++;
			}
			a[1]++;
		}
		a[0]++;
	}
}
