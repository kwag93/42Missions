/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:05:22 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/30 00:35:32 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long			sign;
	long			nbr;

	sign = 1;
	nbr = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-' || *str == '+'))
		str++;
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		nbr = (nbr * 10) + (*str - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
		str++;
	}
	return (nbr * sign);
}
