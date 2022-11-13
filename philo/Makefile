# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hajeong <hajeong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 21:45:41 by hajeong           #+#    #+#              #
#    Updated: 2022/11/11 21:45:41 by hajeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
LIBFT		= libft

SRCS = philo.c philo_util.c init_vars.c make_thread.c action.c
		

OBJS		= $(SRCS:%.c=%.o)

FLAGS		= -Wall -Wextra -Werror -g

all			:	$(NAME)

$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		cc -o $(NAME) $(OBJS) -L ./libft -l ft

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