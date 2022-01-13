NAME = philo
SRCS = src/errors.c src/philo.c src/proc.c src/states.c src/utils.c src/extern.c
OBJS = $(SRCS:.c=.o)
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

.c.o:
#		$(CC) $(CFLAGS) -c -I $(HEADER) $< -o ${<:.c=.o}
		$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
