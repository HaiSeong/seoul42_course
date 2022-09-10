# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 10:28:43 by hajeong           #+#    #+#              #
#    Updated: 2022/09/10 11:00:28 by hajeong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

SRCS = server.c client.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

server: server.o libft
	make -C libft	
	cc -o $@ $< -Llibft -lft

client: client.o libft
	make -C libft	
	cc -o $@ $< -Llibft -lft

server.o: server.c
	cc -c $(FLAGS) server.c

client.o: client.c
	cc -c $(FLAGS) client.c

clean:
	rm -f client.o server.o 
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all bonus clean fclean re
