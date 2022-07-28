/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 10:19:49 by bkwag             #+#    #+#             */
/*   Updated: 2020/05/31 12:00:43 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int temp;
	int index;
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		index = i;
		while (j < size)
		{
			if (tab[index] > tab[j])
				index = j;
			j++;
		}
		temp = tab[index];
		tab[index] = tab[i];
		tab[i] = temp;
		i++;
	}
}
