NAME 		=	philo

CC 			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

SRCS	 =	init_arg.c\
			init_philo.c\
			main.c \
			philo_func.c\
			philo_func2.c\
			philo_util.c


OBJS = $(SRCS:%.c=%.o)

OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)
INCLUDES 	= 	-I./

.PHONY: all clean fclean re bonus

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) -o $@ $^

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re :
		make fclean
		make all