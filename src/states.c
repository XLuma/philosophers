/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaplant <llaplant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:34:33 by llaplant          #+#    #+#             */
/*   Updated: 2022/01/17 16:40:12 by llaplant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../includes/philo.h"

/* Handles sleeping till they die */
void	philo_sleep(int time_to_sleep, t_main *main)
{
	long long	i;

	i = timestamp();
	while (!(main->t_flag.died))
	{
		if (timediff(i, timestamp()) >= time_to_sleep)
			break ;
		usleep(50);
	}
}

/* Eating section. Includes SLEEP, and THINK
at the end. Fixes 1/5 crashing bug somehow */
void	eat(t_philo *philo)
{
	t_main	*main;

	main = philo->main;
	if (philo->time_eaten == main->args.nb_eaten)
		return ;
	pthread_mutex_lock(&(main->mutex.fork[philo->id_left_fork]));
	print(main, philo->id, FORK);
	pthread_mutex_lock(&(main->mutex.fork[philo->id_right_fork]));
	print(main, philo->id, FORK);
	pthread_mutex_lock(&(main->mutex.eat));
	print(main, philo->id, EATING);
	philo->timer = timestamp();
	pthread_mutex_unlock(&(main->mutex.eat));
	philo_sleep(main->args.time_to_eat, main);
	(philo->time_eaten)++;
	pthread_mutex_unlock(&(main->mutex.fork[philo->id_left_fork]));
	pthread_mutex_unlock(&(main->mutex.fork[philo->id_right_fork]));
	print(main, philo->id, SLEEP);
	philo_sleep(main->args.time_to_sleep, main);
	print(main, philo->id, THINK);
}

void	deathcheck(t_philo *philos, t_main *main)
{
	int	i;

	while (!(main->t_flag.all_eaten))
	{
		i = -1;
		while (++i < main->args.nb_philo && !(main->t_flag.died))
		{
			pthread_mutex_lock(&main->mutex.eat_check);
			if (timediff(philos[i].timer, timestamp()) >= main->args.time_die)
			{
				print(main, i, DIED);
				main->t_flag.died = 1;
			}
			pthread_mutex_unlock(&main->mutex.eat_check);
			usleep(100);
		}
		if (main->t_flag.died == 1)
			break ;
		i = -1;
		while (++i < main->args.nb_philo && main->args.nb_eaten != -1
			&& philos[i].time_eaten >= main->args.nb_eaten)
			kill_philo(main, i);
		if (i == main->args.nb_philo)
			main->t_flag.all_eaten = 1;
	}
}

void	exit_proc(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->args.nb_philo)
	{
		if (main->args.nb_philo == 1)
		{
			kill_philo(main, i);
			exit(1);
		}
		else
		{
			if (pthread_join(main->threads[i], NULL) != 0)
				error("There was an error joining threads\n");
			i++;
		}
	}
	i = 0;
	while (i < main->args.nb_philo)
	{
		if (pthread_mutex_destroy(&main->mutex.fork[i]) != 0)
			error("There was an error destroying mutex fork\n");
		i++;
	}
	pthread_mutex_destroy(&main->mutex.print);
}

void	kill_philo(t_main *main, int id)
{
	pthread_cancel(main->threads[id]);
}
