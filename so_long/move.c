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

static int	get_p_position(t_game game)
{
	int	i;

	i = 0;
	while (game.map[i] != 'P')
		i++;
	return i;
}

void move_w(t_game *game)
{
	int	now;
	int	next;

	now = get_p_position(*game);
	next = now - game->map_width;
	if (next < 0)
		return ; //do noting
	if (game->map[next] == 'E' && game->c_cnt == 0)
	{
		game->move_cnt++;
		exit(0); // exit
	}
	else if (game->map[next] == 'C')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->c_cnt--;
		game->move_cnt++;
	}
	else if (game->map[next] == '0')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->move_cnt++;
	}
}

void move_s(t_game *game)
{
	int	now;
	int	next;

	now = get_p_position(*game);
	next = now + game->map_width;
	if (next > (int) ft_strlen(game->map) - 1)
		return ; //do noting
	if (game->map[next] == 'E' && game->c_cnt == 0)
	{
		game->move_cnt++;
		exit(0); // exit
	}
	else if (game->map[next] == 'C')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->c_cnt--;
		game->move_cnt++;
	}
	else if (game->map[next] == '0')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->move_cnt++;
	}
}

void move_d(t_game *game)
{
	int	now;
	int	next;

	now = get_p_position(*game);
	next = now + 1;
	if (now % game->map_width == game->map_width - 1)
		return ; //do noting
	if (game->map[next] == 'E' && game->c_cnt == 0)
	{
		game->move_cnt++;
		exit(0); // exit
	}
	else if (game->map[next] == 'C')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->c_cnt--;
		game->move_cnt++;
	}
	else if (game->map[next] == '0')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->move_cnt++;
	}
}

void move_a(t_game *game)
{
	int	now;
	int	next;

	now = get_p_position(*game);
	next = now - 1;
	if (now % game->map_width == 0)
		return ; //do noting
	if (game->map[next] == 'E' && game->c_cnt == 0)
	{
		game->move_cnt++;
		exit(0); // exit
	}
	else if (game->map[next] == 'C')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->c_cnt--;
		game->move_cnt++;
	}
	else if (game->map[next] == '0')
	{
		game->map[now] = '0';
		game->map[next] = 'P';
		game->move_cnt++;
	}
}
