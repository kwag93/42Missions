/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:03:56 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/09 10:58:57 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	if (nb < 0)
		return (0);
	if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	while (power != 1)
	{
		nb *= nb;
		power--;
	}
	return (nb);
}
