/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:01:08 by bkwag             #+#    #+#             */
/*   Updated: 2021/07/08 10:44:49 by bkwag            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		init_philosophers(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->philo_num)
	{
		game->philosophers[i].is_eating = 0;
		game->philosophers[i].idx = i;
		game->philosophers[i].lfork = i;
		game->philosophers[i].rfork = (i + 1) % game->philo_num;
		game->philosophers[i].eat_cnt = 0;
		game->philosophers[i].game = game;
		pthread_mutex_init(&game->philosophers[i].mutex, NULL);
		pthread_mutex_init(&game->philosophers[i].eat_m, NULL);
		pthread_mutex_lock(&game->philosophers[i].eat_m);
		i++;
	}
}

int			init_mutexes(t_game *game)
{
	int	idx;

	pthread_mutex_init(&game->write_m, NULL);
	pthread_mutex_init(&game->somebody_dead_m, NULL);
	pthread_mutex_lock(&game->somebody_dead_m);
	if (!(ft_malloc(&(game->fork_m),
	sizeof(*(game->fork_m)) * game->philo_num)))
		return (1);
	idx = 0;
	while (idx < game->philo_num)
		pthread_mutex_init(&game->fork_m[idx++], NULL);
	return (0);
}

int			read_argv(t_game *game, int argc, char **argv)
{
	if ((game->philo_num = ft_atoi(argv[1])) < 1)
		return (2);
	if (game->philo_num > 200)
		return (2);
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
	return (init_mutexes(game));
}
