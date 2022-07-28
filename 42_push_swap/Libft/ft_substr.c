/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:47:55 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/30 00:58:33 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	new_len;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_len < start)
	{
		if (!(new = malloc(sizeof(char) * 1)))
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}
