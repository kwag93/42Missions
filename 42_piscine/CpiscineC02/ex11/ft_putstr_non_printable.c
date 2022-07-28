/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:22:38 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/02 15:34:07 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_16base(char c)
{
	int a;
	int b;

	a = c / 16;
	b = c % 16;
	write(1, &"0123456789abcdef"[a], 1);
	write(1, &"0123456789abcdef"[b], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 31 && str[i] < 127))
			ft_putchar(str[i]);
		else
		{
			write(1, "\\", 1);
			ft_16base(str[i]);
		}
		i++;
	}
}
