/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaplant <llaplant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:41:57 by llaplant          #+#    #+#             */
/*   Updated: 2021/11/30 16:21:16 by llaplant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo init_philo(void)
{
	t_philo philo;

	philo.fork = 0;
	philo.is_dead = 0;
	philo.is_eating = 0;
	philo.is_sleeping = 0;
	philo.taken_fork = -1;
	philo.args.time_to_die = -1;
	philo.args.time_to_eat = -1;
	philo.args.time_to_sleep = -1;
	philo.args.nb_philo = 0;
	philo.args.nb_eaten = 0;
	return (philo);
}

void	check_argv(int argc, char **argv, t_philo *philo)
{
	if(ft_atoi(argv[1]) < 2 || argc != 5 || argc != 6)
		printf("Error\n");
	if (argc == 6)
		philo->args.nb_eaten = ft_atoi(argv[5]);
}

int main(int argc, char **argv)
{
	t_philo philo;
	
	philo = init_philo();
	check_argv(argc, argv, &philo);
	//need to think about how to handle number of philos in a good way, seems an allocated array isnt good
	return 0;
}