
NAME		= so_long
LIBFT		= libft

SRCS =	main.c\
		file_check.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		cc -o $(NAME) $(OBJS) -L ./libft -l ft -L ./mlx -l mlx -framework OpenGL -framework AppKit

%.o			:	%.c
		cc $(FLAGS) -c $^ -o $@


clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)

fclean		:	clean
		rm -f $(NAME)
		make fclean -C $(LIBFT)

re			:	fclean all

.PHONY		:	all clean fclean re