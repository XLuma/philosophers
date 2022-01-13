/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaplant <llaplant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:41:57 by llaplant          #+#    #+#             */
/*   Updated: 2022/01/13 12:06:06 by llaplant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	check_argv(int argc, char **argv, t_main *main)
{
	if ((argc < 5 || argc > 6) || ft_atoi(argv[1]) < 2)
		error("Error\n");
	if (argc == 6)
		main->args.nb_eaten = ft_atoi(argv[5]);
	else
		main->args.nb_eaten = -1;
	main->args.nb_philo = ft_atoi(argv[1]);
	main->args.time_die = ft_atoi(argv[2]);
	main->args.time_to_eat = ft_atoi(argv[3]);
	main->args.time_to_sleep = ft_atoi(argv[4]);
}

t_philo	new_philo(int id)
{
	t_philo	ret;

	ret.id = id;
	ret.is_dead = 0;
	ret.time_eaten = 0;
	ret.is_sleeping = 0;
	ret.taken_fork = -1;
	ret.timer = 0;
	return (ret);
}

void	init_mutex(t_main *main)
{
	init_mutex_forks(main);
	pthread_mutex_init(&main->mutex.dead, NULL);
	pthread_mutex_init(&main->mutex.eat, NULL);
	pthread_mutex_init(&main->mutex.print, NULL);
	pthread_mutex_init(&main->mutex.queue, NULL);
	pthread_mutex_init(&main->mutex.eat_check, NULL);
}

int	main(int argc, char **argv)
{
	t_main	main;
	int		i;

	i = 0;
	check_argv(argc, argv, &main);
	while (i < main.args.nb_philo)
	{
		main.philo[i] = new_philo(i);
		i++;
	}
	init_mutex(&main);
	start(&main);
	return (0);
}
