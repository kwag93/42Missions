/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 16:17:03 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/27 13:36:53 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	unsigned char	find;
	size_t			i;

	new_dst = dst;
	new_src = (unsigned char *)src;
	find = c;
	i = 0;
	while (i < n)
	{
		new_dst[i] = new_src[i];
		if (new_src[i] == find)
			return (dst + (i + 1));
		i++;
	}
	return (NULL);
}
