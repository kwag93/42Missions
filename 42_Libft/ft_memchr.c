/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:54:41 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/28 21:37:22 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*s;
	unsigned char	c;
	int				i;

	i = 0;
	s = (unsigned char *)ptr;
	c = (unsigned char)value;
	while (n--)
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}
