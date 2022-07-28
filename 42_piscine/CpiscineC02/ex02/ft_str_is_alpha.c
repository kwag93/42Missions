/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 11:35:35 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/02 16:36:22 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int		ft_str_is_alpha(char *str)
{
	int			i;
	bool		value;
	char		temp;

	i = 0;
	value = 1;
	while (str[i] != '\0')
	{
		temp = str[i];
		if (str[0] == '\0')
			break ;
		if (!((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z')))
		{
			value = 0;
			break ;
		}
		i++;
	}
	return (value);
}
