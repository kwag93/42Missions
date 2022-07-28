/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 16:26:37 by bkwag             #+#    #+#             */
/*   Updated: 2020/12/27 18:05:55 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char		*ft_strchr(char *str, int c)
{
	size_t			i;
	unsigned char	c2;

	if (str == 0)
		return (0);
	c2 = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == c2)
			return (str + i);
		i++;
	}
	return (0);
}

size_t		ft_strlcpy(char *str1, const char *str2, size_t str1size)
{
	size_t str2_len;

	if (!str1 || !str2)
		return (0);
	str2_len = ft_strlen(str2);
	if (str1size == 0)
		return (str2_len);
	while (*str2 && --str1size)
	{
		*str1++ = *str2++;
	}
	*str1 = '\0';
	return (str2_len);
}

size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
