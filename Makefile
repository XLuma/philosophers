NAME = philo
SRCS = src/errors.c src/philo.c src/proc.c src/states.c src/utils.c src/extern.c
OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

all:
	$(CC) $(CFLAGS) -pthread $(SRCS) $(LIBFT) -o $(NAME) -g

clean:
	rm -f $(NAME)

re: clean all
