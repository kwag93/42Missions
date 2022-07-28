/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 14:52:44 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/02 15:38:48 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_str_is_lowercase(char *str)
{
	int		i;
	bool	value;

	i = 0;
	value = true;
	while (str[i] != '\0')
	{
		if (str[0] == '\0')
			break ;
		if (!((str[i] >= 'a' && str[i] <= 'z')))
		{
			value = false;
			break ;
		}
		i++;
	}
	return (value);
}
