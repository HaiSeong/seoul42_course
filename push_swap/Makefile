NAME		= push_swap
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS =	ft_doubly_circular_list.c \
		push_swap.c \
		push.c \
		swap.c \
		reverse_rotate.c \
		rotate.c \
		sorting_before.c\
		sorting.c \
		calculate_cost1.c \
		calculate_cost2.c \
		rotate_best_cost.c \
		

OBJS		= $(SRCS:%.c=%.o)

LIBC		= ar rc

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		cc -o $(NAME) $(OBJS) -Llibft -lft

%.o			:	%.c
		cc $(FLAGS) -c $^ -I./ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re