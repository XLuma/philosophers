/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaplant <llaplant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:34:41 by llaplant          #+#    #+#             */
/*   Updated: 2022/01/13 11:34:43 by llaplant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print(t_main *main, int id, char *str)
{
	long long	i;

	pthread_mutex_lock(&main->mutex.print);
	i = timestamp() - main->t_flag.clock_start;
	if (!(main->t_flag.died))
		printf("%lli %d %s\n", i, id + 1, str);
	pthread_mutex_unlock(&main->mutex.print);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long long	timediff(long long past, long long present)
{
	return (present - past);
}

void	init_mutex_forks(t_main *main)
{
	int	i;
	int	j;

	i = main->args.nb_philo;
	j = 0;
	while (j < i)
	{
		main->philo[j].id_left_fork = j;
		if (j == 0)
			main->philo[j].id_right_fork = main->args.nb_philo - 1;
		else
			main->philo[j].id_right_fork = j - 1;
		pthread_mutex_init(&(main->mutex.fork[j]), NULL);
		j++;
	}
}
