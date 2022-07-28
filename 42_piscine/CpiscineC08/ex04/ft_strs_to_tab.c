/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:23:18 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/16 16:20:18 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int							ft_len(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char						*ft_strdup(char *str)
{
	char	*dest;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_len(str);
	if (!(dest = (char *)malloc(sizeof(char) * (str_len + 1))))
		return (0);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str			*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str		*s_av;
	int						i;

	if (!(s_av = malloc(sizeof(struct s_stock_str) * (ac + 1))))
		return (0);
	i = 0;
	while (i < ac)
	{
		s_av[i].size = ft_len(av[i]);
		s_av[i].str = av[i];
		s_av[i].copy = ft_strdup(av[i]);
		i++;
	}
	s_av[i].size = 0;
	s_av[i].str = 0;
	s_av[i].copy = 0;
	return (s_av);
}
