#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <sys/types.h>
# include <limits.h>
# include <sys/time.h>

# define MAX_THREAD 12

# define SLEEP "is sleeping"
# define THINK "is thinking"
# define EATING "is eating"
# define DIED "died !"
# define FORK "has taken a fork"

typedef int				t_flag;

typedef struct s_main	t_main;
typedef struct s_args	t_args;
typedef struct s_flags	t_flags;
typedef struct s_mutex	t_mutex;
typedef struct s_philo	t_philo;

struct		s_args
{
	int		time_to_eat;
	int		time_die;
	int		time_to_sleep;
	int		nb_eaten;
	int		nb_philo;
};

struct		s_flags
{
	t_flag		died;
	t_flag		nb_eaten;
	t_flag		all_eaten;
	long long	clock_start;
};

struct		s_mutex
{
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
	pthread_mutex_t	eat;
	pthread_mutex_t	queue;
	pthread_mutex_t	eat_check;
	pthread_mutex_t	fork[250];
};

struct 		s_philo
{
	int			id;
	int			id_left_fork;
	int			id_right_fork;
	t_flag		time_eaten;
	t_flag		is_dead;
	t_flag		is_sleeping;
	t_flag		taken_fork;
	long long	timer;
	t_args		args;
	t_mutex		mutex;
	t_main		*main;
};

struct		s_main
{
	t_philo		philo[250];
	pthread_t	threads[250];
	t_mutex		mutex;
	t_args		args;
	t_flags		t_flag;
};

//errors
void		error(char *str);

//setup
void		init_mutex_forks(t_main *main);

//proc
void		start(t_main *main);
void		*proc(void *arg);
void		eat(t_philo *philo);

//time state functions
void		print(t_main *main, int id, char *str);
long long	timediff(long long past, long long present);
long long	timestamp(void);
void		philo_sleep(int time_to_sleep, t_main *main);

//exit
void		kill_philo(t_main *main, int id);
void		deathcheck(t_philo *philos, t_main *main);
void		exit_proc(t_main *main);

//externs
int			ft_atoi(char *str);
void		ft_putstr_fd(char *s, int fd);
#endif