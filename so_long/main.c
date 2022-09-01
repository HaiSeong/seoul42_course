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

static void	press_key(int key, t_game *game)
{
	static	int	move_cnt;

	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_W)
		move_w(game);
	if (key == KEY_A)
		move_a(game);
	if (key == KEY_S)
		move_s(game);
	if (key == KEY_D)
		move_d(game);
	draw_map(*game);
	if (move_cnt != game->move_cnt)
	{
		ft_printf("you moved %d steps!\n", game->move_cnt);
		move_cnt++;
	}
}

int			main(void)
{
	t_game game;

	init_game(&game, "./map.ber");
	read_file(&game);
	check(&game);
	game.win = mlx_new_window(game.mlx, 32 * game.map_width, 32 * game.map_height, "so_long");
	draw_map(game);
	mlx_hook(game.win, X_EVENT_KEY_RELEASE, 0, &press_key, &game);
	mlx_loop(game.mlx);

	return (0);
}