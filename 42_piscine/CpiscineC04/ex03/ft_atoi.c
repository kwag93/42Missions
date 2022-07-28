/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 11:55:24 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/09 17:39:32 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		is_operator(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int n;

	i = 0;
	n = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	while (is_operator(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (is_number(*str))
	{
		n = 10 * n + (*str - '0');
		str++;
	}
	return (sign * n);
}
