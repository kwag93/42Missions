/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:07:42 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/30 00:28:29 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	while (i < n)
	{
		*((char *)new_dst + i) = *((char *)new_src + i);
		i++;
	}
	return (dst);
}
