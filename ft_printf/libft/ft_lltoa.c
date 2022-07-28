/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunyoo <hyunyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 13:44:49 by hyunyoo           #+#    #+#             */
/*   Updated: 2020/11/02 14:54:47 by hyunyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		get_nb_digit(size_t n_l, int sign)
{
	size_t	nb_digit;

	if (n_l == 0)
		return (1);
	nb_digit = 0;
	while (n_l > 0)
	{
		n_l /= 10;
		nb_digit++;
	}
	if (sign == -1)
		nb_digit++;
	return (nb_digit);
}

static void			convert_nb(char *outstr, size_t n_l, size_t nb_digit,
		int sign)
{
	outstr[nb_digit] = '\0';
	outstr[--nb_digit] = n_l % 10 + '0';
	n_l /= 10;
	while (n_l > 0)
	{
		outstr[--nb_digit] = n_l % 10 + '0';
		n_l /= 10;
	}
	if (sign == -1)
		outstr[0] = '-';
}

char				*ft_lltoa(long long n)
{
	char			*outstr;
	size_t			n_l;
	size_t			nb_digit;
	size_t			sign;

	sign = 1;
	if (n < 0)
	{
		n_l = n * -1;
		sign = -1;
	}
	else
		n_l = n;
	nb_digit = get_nb_digit(n_l, sign);
	if (!(outstr = malloc(sizeof(char) * nb_digit + 1)))
		return (NULL);
	convert_nb(outstr, n_l, nb_digit, sign);
	return (outstr);
}
