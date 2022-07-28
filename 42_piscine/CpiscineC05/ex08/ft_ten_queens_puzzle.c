/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:49:05 by bkwag             #+#    #+#             */
/*   Updated: 2020/06/09 16:13:36 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void path(int row)
{
	int n;
	int flag;
	int cnt;
	int i;
	int j;

	i = 0;
	j = 0;
	if (row == n )
	{
		cnt++;
		return;
	}
	while (i < n)
	{
		flag = 1;
		while (j < y)
		{
			if (puzzle[j] == i || (y-j) == (i-puzzle[j]))
			{
				flag = 0;
				break;
			}	
			j++;
		}
		if(flag)
		{
			puzzle[y] = i;
			path(y + 1);
		}
	}
}

int	ft_ten_qeens_puzzle(void)
{
	int puzzle[10];

	fill_the_puzzle()


}
