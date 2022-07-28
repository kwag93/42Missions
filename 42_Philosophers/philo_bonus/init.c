/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:01:08 by bkwag             #+#    #+#             */
/*   Updated: 2021/07/08 10:41:03 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_philosophers(t_game *game)
{
	int		i;
	char	buffer[50];

	i = 0;
	while (i < game->philo_num)
	{
		game->philosophers[i].is_eating = 0;
		game->philosophers[i].idx = i;
		game->philosophers[i].eat_cnt = 0;
		game->philosophers[i].game = game;
		ft_sem_name(SEMAPHORE_PHILO, (char*)buffer, i);
		sem_unlink(buffer);
		if ((game->philosophers[i].mutex = ft_sem_open(buffer, 1)) < 0)
			return (1);
		ft_sem_name(SEMAPHORE_EAT, (char*)buffer, i);
		sem_unlink(buffer);
		if ((game->philosophers[i].eat_m = ft_sem_open(buffer, 0)) < 0)
			return (1);
		i++;
	}
	return (0);
}

int		init_semaphores(t_game *game)
{
	sem_unlink(SEMAPHORE_FORK);
	sem_unlink(SEMAPHORE_WRITE);
	sem_unlink(SEMAPHORE_DEAD);
	sem_unlink(SEMAPHORE_DEADW);
	if ((game->fork_m = ft_sem_open(SEMAPHORE_FORK, game->philo_num)) < 0)
		return (1);
	if ((game->write_m = ft_sem_open(SEMAPHORE_WRITE, 1)) < 0
		|| (game->somebody_dead_m = ft_sem_open(SEMAPHORE_DEAD, 0)) < 0
		|| (game->dead_write_m = ft_sem_open(SEMAPHORE_DEADW, 1)) < 0)
		return (1);
	return (0);
}

int		read_argv(t_game *game, int argc, char **argv)
{
	if ((game->philo_num = ft_atoi(argv[1])) < 1)
		return (2);
	if (game->philo_num > 200)
		return (1);
	game->ttd = ft_atoi(argv[2]);
	game->tte = ft_atoi(argv[3]);
	game->tts = ft_atoi(argv[4]);
	if (argc == 6)
		game->least_eat_num = ft_atoi(argv[5]);
	else
		game->least_eat_num = 0;
	game->dead = 0;
	game->fork_m = NULL;
	game->philosophers = NULL;
	if (!(ft_malloc(&game->philosophers,
	sizeof(*(game->philosophers)) * game->philo_num)))
		return (1);
	init_philosophers(game);
	return (init_semaphores(game));
}
