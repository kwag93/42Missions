/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:37:03 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/30 01:01:06 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		s1_len;
	int		s2_len;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(new = malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	ft_strlcpy(new, s1, s1_len + 1);
	ft_strlcat(new + (s1_len), s2, s2_len + 1);
	return (new);
}
