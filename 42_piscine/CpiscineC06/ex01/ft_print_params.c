/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:01:39 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/09 11:04:12 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int argc, char *argv[])
{
	int i;

	i = 1;
	if (argc > 0)
	{
		while (argv[i])
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}
