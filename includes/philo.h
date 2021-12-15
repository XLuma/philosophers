#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <sys/types.h>

#define MAX_THREAD 6

#ifdef __linux
# define MAX_THREAD 16
#endif

typedef int flag;

typedef struct 		s_args
{
	double time_to_eat;
	double time_to_die;
	double time_to_sleep;
	int	nb_eaten; //5th optional arg
	int	nb_philo;
} 					t_args;

typedef struct		s_mutex
{
	pthread_mutex_t	print; //lock for printing
	pthread_mutex_t dead; //lock for death
	pthread_mutex_t eat; //lock for eating ???
	pthread_mutex_t queue; //lock for queue ?
}					t_mutex;

typedef struct 		s_philo
{
	flag fork; //0 if not taken, 1 if taken
	flag is_eating; //0 if not eating, 1 if eating
	flag is_dead; //0 if not dead, 1 if dead
	flag is_sleeping; //0 if not sleeping, 1 if sleeping
	flag taken_fork; //this should represent a philo number, otherwise -1
	double timer; //timer ??
	t_args args; //struct for program arguments
} 					t_philo;

#endif