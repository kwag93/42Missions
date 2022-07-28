/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:48:47 by bkwag             #+#    #+#             */
/*   Updated: 2020/11/02 14:53:05 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *str, size_t n)
{
	char	*newstr;
	size_t	len;
	size_t	i;

	i = 0;
	if (n <= 0 || !(len = ft_strlen(str)))
		return (ft_strdup(""));
	len = n < len ? n : len;
	if (!(newstr = malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
