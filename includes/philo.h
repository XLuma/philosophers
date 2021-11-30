#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <sys/types.h>

typedef int flag;

typedef struct 		s_timevalue
{
	double time_to_eat;
	double time_to_die;
	double time_to_sleep;
} 					t_timevalue;

typedef struct 		s_philo
{
	flag fork; //0 if not taken, 1 if taken
	flag is_eating; //0 if not eating, 1 if eating
	flag is_dead; //0 if not dead, 1 if dead
	flag is_sleeping; //0 if not sleeping, 1 if sleeping
	flag taken_fork; //this should represent a philo number, otherwise -1
	double timer; //timer ??
	t_timevalue time;
} 					t_philo;

#endif