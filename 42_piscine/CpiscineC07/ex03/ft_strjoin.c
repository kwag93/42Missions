/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 16:43:48 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/17 15:34:22 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			ft_strlen(char *str)
{
	int cnt;

	cnt = 0;
	while (*str++)
		cnt++;
	return (cnt);
}

int			ft_length(char **str, int size, int sep_len)
{
	int	cnt;
	int i;

	cnt = 0;
	i = 0;
	while (i < size)
	{
		cnt += ft_strlen(str[i]);
		cnt += sep_len;
		i++;
	}
	cnt -= sep_len;
	return (cnt);
}

char		*ft_strcat(char *str1, char *str2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str1[i])
		i++;
	while (str2[j])
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[i + j] = '\0';
	return (str1);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		full_len;
	int		i;

	i = 0;
	if (!(size))
		return ((char *)malloc(sizeof(char)));
	full_len = ft_length(strs, size, ft_strlen(sep));
	if (!(str = (char *)malloc(sizeof(char) * (full_len + 1))))
		return (0);
	*str = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
		{
			ft_strcat(str, sep);
		}
		i++;
	}
	return (str);
}
