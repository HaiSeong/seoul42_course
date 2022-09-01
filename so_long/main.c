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

static int	exit_game(t_game *game)
{
	ft_printf("Exit game\n");
	free(game->map);
	exit(0);
}

static int	key_release(int key, t_game *game)
{
	if (key == KEY_ESC)
		exit_game(game);
	if (key == KEY_W)
		move_w(game);
	if (key == KEY_A)
		move_a(game);
	if (key == KEY_S)
		move_s(game);
	if (key == KEY_D)
		move_d(game);
	draw_map(*game);
	return (0);
}

int			main(int argc, char *argv[])
{
	t_game	game;
	int		i;

	if (argc < 2)
		print_error("We need argument");
	else if (argc > 2)
		print_error("Too many arguments");
	i = 0;
	while (argv[1][i] != '\0')
		i++;
	if (ft_strncmp(&argv[1][i-4], ".ber", 4) != 0)
		print_error("The file must be *.ber");
	if (open(argv[1],O_RDONLY) < 0)
		print_error("Check the file name again");
	init_game(&game, argv[1]);
	read_file(&game);
	check(&game);
	game.win = mlx_new_window(game.mlx, 32 * game.map_width, 32 * game.map_height, "so_long");
	draw_map(game);
	mlx_hook(game.win, KEY_RELEASE, 0, &key_release, &game);
	mlx_hook(game.win, KEY_EXIT, 0, &exit_game, &game);
	mlx_loop(game.mlx);
}