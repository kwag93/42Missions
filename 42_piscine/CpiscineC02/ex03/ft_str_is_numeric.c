/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numberic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:25:53 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/02 15:39:20 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_str_is_numeric(char *str)
{
	int		i;
	bool	value;

	i = 0;
	value = 1;
	while (str[i] != '\0')
	{
		if (str[0] == '\0')
			break ;
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			value = 0;
			break ;
		}
		i++;
	}
	return (value);
}
