/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyulee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 09:52:21 by hyulee            #+#    #+#             */
/*   Updated: 2020/05/30 10:56:36 by hyulee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern	void	ft_putchar(char c);

void			start(int x)
{
	int		cnt;

	cnt = 0;
	while (cnt < x)
	{
		if (cnt == 0)
			ft_putchar('A');
		else if (cnt == x - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
		cnt++;
	}
}

void			mid(int x)
{
	int		cnt;

	cnt = 0;
	while (cnt < x)
	{
		if (cnt == 0 || cnt == x - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		cnt++;
	}
}

void			end(int x)
{
	int		cnt;

	cnt = 0;
	while (cnt < x)
	{
		if (cnt == 0)
			ft_putchar('C');
		else if (cnt == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
		cnt++;
	}
}

void			rush(int x, int y)
{
	int		i;

	i = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (i < y)
	{
		if (i == 0)
			start(x);
		else if (i == y - 1)
			end(x);
		else
			mid(x);
		ft_putchar('\n');
		i++;
	}
}
