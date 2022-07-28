/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 15:42:25 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/09 16:35:05 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		ex_check(char *base)
{
	int i;
	int j;
	int len;

	len = 0;
	while (*base++)
		len++;
	i = 0;
	if (len == 1 || len == 0)
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		if (is_space(base[i]))
			return (0);
		if ((base[i] == '+') || (base[i] == '-'))
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	recursive(int n, char *base, int len)
{
	if (n == 0)
		return ;
	recursive(n / len, base, len);
	write(1, &(base[n % len]), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	len = 0;
	while (*base++)
		len++;
	if (ex_check(base))
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			recursive(-(nbr / len), base, len);
			write(1, &(base[-(nbr % len)]), 1);
		}
		else if (nbr < 0)
		{
			nbr *= -1;
			ft_putchar('-');
			recursive(nbr, base, len);
		}
		else if (nbr == 0)
			write(1, &(base[0]), 1);
		else
			recursive(nbr, base, len);
	}
}
