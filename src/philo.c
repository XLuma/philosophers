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
	philo.time.time_to_die = -1;
	philo.time.time_to_eat = -1;
	philo.time.time_to_sleep = -1;
	return (philo);
}

int main(int argc, char **argv)
{
	t_philo philo;
	
	philo = init_philo();
	
	return 0;
}