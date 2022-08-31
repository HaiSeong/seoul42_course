/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:39:12 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/31 20:02:34 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game.map_height)
	{
		j = 0;
		while (j < game.map_width)
		{
			mlx_put_image_to_window(game.mlx, game.win, game.img_grass, j * 32, i * 32);
			if (game.map[i * game.map_width + j] == '1')
				mlx_put_image_to_window(game.mlx, game.win, game.img_wall, j * 32, i * 32);
			else if (game.map[i * game.map_width + j] == 'C')
				mlx_put_image_to_window(game.mlx, game.win, game.img_coin, j * 32, i * 32);
			else if (game.map[i * game.map_width + j] == 'E')
				mlx_put_image_to_window(game.mlx, game.win, game.img_exit, j * 32, i * 32);
			else if (game.map[i * game.map_width + j] == 'P')
				mlx_put_image_to_window(game.mlx, game.win, game.img_person, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
