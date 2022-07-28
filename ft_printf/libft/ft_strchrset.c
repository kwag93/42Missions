/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:43:56 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/02 14:53:05 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchrset(char *s, const char *set)
{
	size_t	i;
	size_t	j;

	if (!s || !set)
		return (0);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (0);
}
