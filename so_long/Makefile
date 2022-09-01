
NAME		= so_long
LIBFT		= libft
MLX			= mlx

SRCS =	main.c\
		so_long_util.c\
		read_file.c\
		check.c\
		draw_map.c\
		init_game.c\
		move.c\
		error.c

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		make all -C $(MLX)/
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