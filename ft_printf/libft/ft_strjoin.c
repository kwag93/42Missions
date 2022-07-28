/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:03:20 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/07/09 15:14:13 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len1;
	int		len2;
	int		idx;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(newstr = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
	{
		return (NULL);
	}
	i = 0;
	idx = 0;
	while (s1[i])
	{
		newstr[idx++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		newstr[idx++] = s2[i++];
	}
	newstr[idx] = 0;
	return (newstr);
}
