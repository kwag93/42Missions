/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:47:11 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/30 01:02:30 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		getstart(const char *s1, const char *set)
{
	size_t len;
	size_t i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int		getend(const char *s1, const char *set)
{
	size_t len;
	size_t i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - 1 - i]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = getstart(s1, set);
	end = getend(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	if (!(new = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	ft_strlcpy(new, s1 + start, end - start + 1);
	return (new);
}
