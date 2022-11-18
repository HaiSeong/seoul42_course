NAME 		=	philo

CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRCS	 =	init_vars.c\
			init_philo.c\
			main.c \
			philo_func.c\
			philo_func2.c\
			philo_util.c


OBJS = $(SRCS:%.c=%.o)

OBJS		=	$(SRCS:.c=.o)

.PHONY: all clean fclean re bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re :
		make fclean
		make all