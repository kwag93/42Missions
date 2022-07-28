/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 09:48:09 by bkwag             #+#    #+#             */
/*   Updated: 2020/05/31 10:45:05 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	char nstr;

	while (1)
	{
		nstr = *str;
		if (nstr == '\0')
		{
			break ;
		}
		ft_putchar(nstr);
		str++;
	}
}
