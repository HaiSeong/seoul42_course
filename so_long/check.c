/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 20:32:41 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/28 20:40:25 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_lines(t_game *game)
{
	char	**lines;
	int		i;

	lines = ft_split(game->map, '\n');
	if (lines == NULL)
		free_map_print_error(game, "System error, reboot game");
	game->map_width = ft_strlen(lines[0]);
	i = 1;
	while (lines[i] != NULL)
	{
		if ((int)ft_strlen(lines[i++]) != game->map_width)
			free_map_strs_print_error(game, lines, "Map is not rectangular");
	}
	game->map_height = i;
	free_strs(lines);
}

void	del_newline(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((game->map)[i] != '\0')
	{
		if ((game->map)[i] == '\n')
		{
			i++;
			if ((game->map)[i] == '\n')
				free_map_print_error(game, "Too much new lines");
		}
		else
			(game->map)[j++] = (game->map)[i++];
	}
	(game->map)[j] = '\0';
}

void	check_wall(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while ((game->map)[i] != '\0')
	{
		x = i % game->map_width;
		y = i / game->map_width;
		if (x == 0 || x == game->map_width - 1
			|| y == 0 || y == game->map_height - 1)
		{
			if ((game->map)[i] != '1')
				free_map_print_error(game, "Map should be walled in");
		}
		i++;
	}
}

void	check_object(t_game *game)
{
	int	i;

	i = 0;
	game->c_cnt = 0;
	game->e_cnt = 0;
	game->p_cnt = 0;
	while ((game->map)[i] != '\0')
	{
		if (!((game->map)[i] == '0' || (game->map)[i] == '1'
			|| (game->map)[i] == 'C' || (game->map)[i] == 'E'
			|| (game->map)[i] == 'P'))
			free_map_print_error(game,
				"There are strange characters on the map");
		if ((game->map)[i] == 'C')
			(game->c_cnt)++;
		else if ((game->map)[i] == 'E')
			(game->e_cnt)++;
		else if ((game->map)[i] == 'P')
			(game->p_cnt)++;
		i++;
	}
	if (!(game->c_cnt > 0 && game->e_cnt > 0 && game->p_cnt == 1))
		free_map_print_error(game,
			"Map is not valid\nP sould be 1, And E and C must be one or more");
}

void	check(t_game *game)
{
	check_lines(game);
	del_newline(game);
	check_wall(game);
	check_object(game);
}
