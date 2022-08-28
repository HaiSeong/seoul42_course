/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:29:09 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/28 20:39:47 by hajeong          ###   ########.fr       */
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
	// void		*mlx;
	// void		*win;
	// t_param		param;

	// param_init(&param);
	// mlx = mlx_init();
	// win = mlx_new_window(mlx, 500, 500, "mlx_project");
	// mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
	// mlx_loop(mlx);

	// t_vars	vars;		// ESC를 누르면 창이 닫아지는 예제
	// vars.mlx = mlx_init();
	// vars.win = mlx_new_window(vars.mlx, 1920, 1080, "hello world!");
	// mlx_hook(vars.win, X_EVENT_KEY_RELEASE, 0, close, &vars);
	// mlx_hook(vars.win, 4, 1L<<0, close1, &vars);
	// mlx_loop(vars.mlx);

	t_game game;
	game.file = "./map.ber";
	game.map = ft_strdup("");
	read_file(&game);
	char **strs = ft_split(game.map, '\n');
	int i=0;
	while (strs[i] != NULL)
	{
		ft_printf("%s", strs[i++]);
	}
	ft_printf("\n\n");
	
	check_lines(&game);
	ft_printf("width : %d\n", game.map_width);
	ft_printf("height : %d\n", game.map_height);

	
	void *mlx;
	void *win;
	void *img;
	// void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	void *img7;
	void *img8;
	void *img9;
	int img_width;
	int img_height;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "my_mlx");
	img = mlx_xpm_file_to_image(mlx, "./asset/blocks.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(mlx, "./asset/coin.xpm", &img_width, &img_height);
	img4 = mlx_xpm_file_to_image(mlx, "./asset/exit.xpm", &img_width, &img_height);
	img5 = mlx_xpm_file_to_image(mlx, "./asset/mario0.xpm", &img_width, &img_height);
	img6 = mlx_xpm_file_to_image(mlx, "./asset/mario1.xpm", &img_width, &img_height);
	img7 = mlx_xpm_file_to_image(mlx, "./asset/mario2.xpm", &img_width, &img_height);
	img8 = mlx_xpm_file_to_image(mlx, "./asset/mario3.xpm", &img_width, &img_height);
	img9 = mlx_xpm_file_to_image(mlx, "./asset/mario4.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img3, 16, 0);
	mlx_put_image_to_window(mlx, win, img4, 32, 0);
	mlx_put_image_to_window(mlx, win, img5, 0, 16);
	mlx_put_image_to_window(mlx, win, img6, 16, 16);
	mlx_put_image_to_window(mlx, win, img7, 32, 16);
	mlx_put_image_to_window(mlx, win, img7, 128, 128);
	mlx_put_image_to_window(mlx, win, img7, 128, 144);
	mlx_loop(mlx);


	return (0);
}