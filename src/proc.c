/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaplant <llaplant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:34:24 by llaplant          #+#    #+#             */
/*   Updated: 2022/01/13 11:34:26 by llaplant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*proc(void *arg)
{
	int		i;
	t_main	*main;
	t_philo	*philo;

	philo = (t_philo *)arg;
	i = 0;
	main = philo->main;
	if (philo->id % 2)
		usleep(15000);
	while (!(main->t_flag.died))
	{
		eat(philo);
		if (main->t_flag.all_eaten)
			break ;
		i++;
	}
	return (NULL);
}

void	assign_args(t_main *main)
{
	int	i;

	i = main->args.nb_philo;
	while (--i >= 0)
	{
		main->philo[i].args = main->args;
		main->philo[i].main = main;
	}
}

void	start(t_main *main)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = main->philo;
	main->t_flag.died = 0;
	main->t_flag.all_eaten = 0;
	main->t_flag.nb_eaten = 0;
	main->t_flag.clock_start = timestamp();
	assign_args(main);
	while (i < main->args.nb_philo)
	{
		pthread_create(&main->threads[i], NULL, &proc, &(main->philo[i]));
		philo[i].timer = timestamp();
		i++;
	}
	deathcheck(main->philo, main);
	exit_proc(main);
	printf("End\n");
}
