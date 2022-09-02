/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:11:38 by hajeong           #+#    #+#             */
/*   Updated: 2022/09/02 11:36:14 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define KEY_RELEASE 	3
# define KEY_EXIT 		17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_game {
	void	*mlx;
	void	*win;
	char	*file;
	char	*map;
	int		map_width;
	int		map_height;
	int		c_cnt;
	int		e_cnt;
	int		p_cnt;
	int		move_cnt;
	void	*img_grass;
	void	*img_person;
	void	*img_wall;
	void	*img_exit;
	void	*img_coin;
}	t_game;

char	*join_and_free(char *str1, char *str2);
void	free_strs(char **strs);

void	init_game(t_game *game, char *file);

void	read_file(t_game *game);

void	check_lines(t_game *game);
void	del_newline(t_game *game);
void	check_wall(t_game *game);
void	check_object(t_game *game);
void	check(t_game *game);

void	draw_map(t_game game);

void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	move_a(t_game *game);

void	print_error(char *error_msg);
void	free_buffer_print_error(char *buffer, char *error_msg);
void	free_map_print_error(t_game *game, char *error_msg);
void	free_map_strs_print_error(t_game *game, char **strs, char *error_msg);
#endif