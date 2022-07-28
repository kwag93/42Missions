/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:55:08 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/02 15:38:57 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_str_is_uppercase(char *str)
{
	int		i;
	bool	value;

	i = 0;
	value = true;
	while (str[i] != '\0')
	{
		if (str[0] == '\0')
			break ;
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
		{
			value = false;
			break ;
		}
		i++;
	}
	return (value);
}
