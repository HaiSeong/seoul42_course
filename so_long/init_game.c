/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:11:31 by hajeong           #+#    #+#             */
/*   Updated: 2022/09/02 11:31:34 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game, char *file)
{
	int	img_width;
	int	img_height;

	game->file = file;
	game->map = ft_strdup("");
	if (game->map == NULL)
		print_error("System error, reboot game");
	game->mlx = mlx_init();
	game->c_cnt = 0;
	game->e_cnt = 0;
	game->p_cnt = 0;
	game->move_cnt = 0;
	game->img_grass = mlx_xpm_file_to_image(game->mlx,
			"./asset/grass.xpm", &img_width, &img_height);
	game->img_person = mlx_xpm_file_to_image(game->mlx,
			"./asset/person.xpm", &img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./asset/wall.xpm", &img_width, &img_height);
	game->img_coin = mlx_xpm_file_to_image(game->mlx,
			"./asset/coin.xpm", &img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./asset/exit.xpm", &img_width, &img_height);
}
