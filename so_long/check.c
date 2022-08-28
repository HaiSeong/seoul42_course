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

# include "so_long.h"

void	check_lines(t_game *game)
{
	char	**lines;
	int		i;

	lines = ft_split(game->map, '\n');
	if (lines == NULL)
		;// error
	game->map_width = ft_strlen(lines[0]);
	i = 1;
	while (lines[i] != NULL)
	{
		if ((int)ft_strlen(lines[i++]) != game->map_width)
			exit(1);// error
	}
	game->map_height = i;
	i = 0;
	while (lines[i] != NULL)
		free(lines[i++]);
	free(lines);
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
				exit(1);// error
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
				exit(1);// error
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
			exit(1);// error
		if ((game->map)[i] == 'C')
			(game->c_cnt)++;
		else if ((game->map)[i] == 'E')
			(game->e_cnt)++;
		else if ((game->map)[i] == 'P')
			(game->p_cnt)++;
		i++;
	}
	if (!(game->c_cnt > 0 && game->e_cnt > 0 && game->p_cnt == 1))
		exit(1);//error
}

void	check(t_game *game)
{
	check_lines(game);
	del_newline(game);
	check_wall(game);
	check_object(game);
}