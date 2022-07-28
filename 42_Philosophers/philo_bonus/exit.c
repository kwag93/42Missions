/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:23:37 by bkwag             #+#    #+#             */
/*   Updated: 2021/06/28 14:46:07 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		clear(t_game *game)
{
	int		i;
	char	buffer[50];

	usleep(100);
	sem_unlink(SEMAPHORE_FORK);
	sem_unlink(SEMAPHORE_WRITE);
	sem_unlink(SEMAPHORE_DEAD);
	sem_unlink(SEMAPHORE_DEADW);
	if (game->philosophers)
	{
		i = 0;
		while (i < game->philo_num)
		{
			ft_sem_name(SEMAPHORE_PHILO, (char*)buffer, i);
			sem_unlink(buffer);
			ft_sem_name(SEMAPHORE_EAT, (char*)buffer, i);
			sem_unlink(buffer);
			i++;
		}
		free(game->philosophers);
	}
	return (1);
}

int		ft_error(char *msg)
{
	ft_putstr_fd(msg, 1);
	return (1);
}
