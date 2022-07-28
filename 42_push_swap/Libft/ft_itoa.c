/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:06:25 by bkwag             #+#    #+#             */
/*   Updated: 2020/07/30 00:56:34 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_abs(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int			ft_len(long int nbr)
{
	int	len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int nbr)
{
	int		len;
	int		sign;
	char	*str;

	sign = (nbr < 0) ? -1 : 1;
	len = ft_len(nbr);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = ft_abs(nbr % 10) + '0';
		nbr = ft_abs(nbr / 10);
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
