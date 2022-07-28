/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:42:38 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/09 10:59:42 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long long int i;
    long long int sqrt;

	i = 1;
	if (nb < 0)
		return (0);
    if (nb <= 1)
        return (nb);
	while ((sqrt = (i * i)) < nb)
	{
		i++;
	}
	if (sqrt == nb)
		return (i);
	else
		return (0);
}
