/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:41:05 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/09 15:23:42 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	recursive(int n)
{
	if (n == 0)
		return ;
	recursive(n / 10);
	ft_putchar((n % 10) + 48);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		recursive(147483648);
	}
	else if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
		recursive(nb);
	}
	else if (nb == 0)
		ft_putchar('0');
	else
		recursive(nb);
}
