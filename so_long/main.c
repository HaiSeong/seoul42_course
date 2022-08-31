/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:29:09 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/31 21:44:04 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// #include <stdio.h>

// # define X_EVENT_KEY_PRESS			2
// # define X_EVENT_KEY_RELEASE		3

// # define KEY_ESC		53
// # define KEY_W			13
// # define KEY_A			0
// # define KEY_S			1
// # define KEY_D			2

// typedef struct s_param{
// 	int		x;
// 	int		y;
// }				t_param;

// typedef struct  s_vars {
//     void        *mlx;
//     void        *win;
// }               t_vars;



// void			param_init(t_param *param)
// {
// 	param->x = 3;
// 	param->y = 4;
// }

// int				key_press(int keycode, t_param *param)
// {
// 	static int a = 0;

// 	if (keycode == KEY_W)
// 		param->y++;
// 	else if (keycode == KEY_S)
// 		param->y--;
// 	else if (keycode == KEY_A)
// 		param->x--;
// 	else if (keycode == KEY_D)
// 		param->x++;
// 	else if (keycode == KEY_ESC)
// 		exit(0);
// 	printf("x: %d, y: %d\n", param->x, param->y);
// 	return (0);
// }

// int close(int keycode, t_vars *vars)
// {
// 	if (keycode == KEY_ESC)
// 		mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }
// int close1(int keycode, t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

int			main(void)
{
	t_game game;

	init_game(&game, "./map.ber");
	read_file(&game);
	check(&game);
	move_s(&game);
	draw_map(game);
	mlx_loop(game.mlx);


	return (0);
}