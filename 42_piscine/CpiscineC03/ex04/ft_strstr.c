/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 14:53:36 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/04 15:35:03 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int	leng;

	leng = 0;
	while (str[leng] != '\0')
	{
		leng++;
	}
	return (leng);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	if (!*to_find)
		return (str);
	while (*str != '\0')
	{
		i = 0;
		if (*str == *to_find)
		{
			while (*(str + i) != '\0' && *(to_find + i) != '\0'
					&& *(str + i) == *(to_find + i))
			{
				i++;
			}
			if (i == ft_strlen(to_find))
				return (str);
		}
		str++;
	}
	return (NULL);
}
