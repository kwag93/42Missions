/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 13:05:22 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/15 11:22:07 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/push_swap.h"

int		ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

int		ft_atoi(const char *str)
{
	long			sign;
	long			nbr;

	sign = 1;
	nbr = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (((*str != '-') && ft_strlen(str) > 10)
	|| ((*str == '-') && ft_strlen(str) > 11))
		ft_error();
	if (*str == '-')
		sign = -1;
	if ((*str == '-' || *str == '+'))
		str++;
	while (*str && (*str >= '0') && (*str <= '9'))
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	if ((*str && !ft_isspace(*str)) || ((sign == 1 && nbr > FT_INT_MAX)
	|| (sign == -1 && nbr > FT_INT_MIN)))
		ft_error();
	return (nbr * sign);
}
