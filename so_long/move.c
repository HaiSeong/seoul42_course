/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:57:16 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/31 21:43:53 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_game *game, int now, int next)
{
	if (game->map[next] == 'E' && game->c_cnt == 0)
	{
		game->move_cnt++;
		ft_printf("Success! Score : %d steps!\n", game->move_cnt);
		exit(0); // exit
	}
	else if (game->map[next] == 'C')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->c_cnt--;
		game->move_cnt++;
		ft_printf("you moved %d steps!\n", game->move_cnt);
	}
	else if (game->map[next] == '0')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->move_cnt++;
		ft_printf("you moved %d steps!\n", game->move_cnt);
	}
}

void move_w(t_game *game)
{
	int	now;
	int	next;

	now = 0;
	while (game->map[now] != 'P')
		now++;
	next = now - game->map_width;
	if (next < 0)
		return ; //do noting
	move(game, now, next);
}

void move_s(t_game *game)
{
	int	now;
	int	next;

	now = 0;
	while (game->map[now] != 'P')
		now++;
	next = now + game->map_width;
	if (next > (int) ft_strlen(game->map) - 1)
		return ; //do noting
	move(game, now, next);
}

void move_d(t_game *game)
{
	int	now;
	int	next;

	now = 0;
	while (game->map[now] != 'P')
		now++;
	next = now + 1;
	if (now % game->map_width == game->map_width - 1)
		return ; //do noting
	move(game, now, next);
}

void move_a(t_game *game)
{
	int	now;
	int	next;

	now = 0;
	while (game->map[now] != 'P')
		now++;
	next = now - 1;
	if (now % game->map_width == 0)
		return ; //do noting
	move(game, now, next);
}
