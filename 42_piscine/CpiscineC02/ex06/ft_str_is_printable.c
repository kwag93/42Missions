/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:20:25 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/02 15:39:43 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_str_is_printable(char *str)
{
	int		i;
	bool	value;
	char	temp;

	i = 0;
	value = true;
	while (str[i] != '\0')
	{
		temp = str[i];
		if (str[0] == '\0')
			value = true;
		if (!((temp > 31 && temp < 127)))
		{
			value = false;
			break ;
		}
		i++;
	}
	return (value);
}
