/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 14:30:20 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/30 01:01:58 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*new_ptr;
	unsigned char	src;
	size_t			i;

	new_ptr = ptr;
	src = value;
	i = 0;
	while (i++ < len)
	{
		*new_ptr++ = value;
	}
	return (ptr);
}
