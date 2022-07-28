/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:26:56 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/09 11:31:08 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_swap(char **str1, char **str2)
{
	char *temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	while (1)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
		{
			if (c1 < c2)
				return (-1);
			else
				return (1);
		}
		if (!c1)
			break ;
	}
	return (0);
}

void	ft_sort(int argc, char **argv)
{
	int		index;
	int		i;
	int		j;

	i = 0;
	while (i++ < argc)
	{
		j = i + 1;
		index = i;
		while (j < argc)
		{
			if (ft_strcmp(argv[index], argv[j]) > 0)
				index = j;
			j++;
		}
		ft_swap(&argv[index], &argv[i]);
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc > 2)
	{
		ft_sort(argc, argv);
		while (++i < argc)
		{
			ft_putstr(argv[i]);
			write(1, "\n", 1);
		}
	}
	return (0);
}
