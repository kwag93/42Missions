/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:24:02 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/27 13:55:00 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	char	*start;

	start = (char *)str;
	while (*str++)
		;
	while (--str != start && *str != c)
		;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
