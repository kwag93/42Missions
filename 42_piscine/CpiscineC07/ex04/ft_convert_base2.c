/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:20:43 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/17 09:52:31 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			ft_atoi_base(char *str, char *base);
int			error_check(char *str);
int			ft_len(char *str);

long int	ft_abs(long int nbr)
{
	return ((nbr < 0) ? -nbr : nbr);
}

int			ft_nlen(long int nbr, int radix)
{
	int len;

	len = (nbr <= 0) ? 1 : 0;
	while (nbr != 0)
	{
		nbr /= radix;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(long long int n, char *base_to)
{
	long int	radix;
	long int	n_len;
	int			sign;
	char		*c;

	sign = (n < 0) ? -1 : 1;
	radix = ft_len(base_to);
	n_len = ft_nlen(n, radix);
	if (!(c = (char *)malloc(sizeof(char) * (n_len + 1))))
		return (0);
	c[n_len] = '\0';
	n_len--;
	while (n_len >= 0)
	{
		c[n_len] = base_to[ft_abs(n % radix)];
		n = ft_abs(n / radix);
		n_len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long int number;

	if (!nbr || error_check(base_from) || error_check(base_to))
		return (0);
	number = ft_atoi_base(nbr, base_from);
	return (ft_itoa_base(number, base_to));
}
