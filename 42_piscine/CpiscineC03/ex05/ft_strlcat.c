/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:28:38 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/03 17:55:33 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int	leng;

	leng = 0;
	while (str[leng] != '\0')
	{
		leng++;
	}
	return (leng);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int d_len;
	unsigned int s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (d_len < size)
		s_len += d_len;
	else
		s_len += size;
	if (size > 0)
	{
		while (src[i] != '\0' && i + d_len < (size - 1))
		{
			dest[i + d_len] = src[i];
			i++;
		}
		dest[d_len + i] = '\0';
	}
	return (s_len);
}
