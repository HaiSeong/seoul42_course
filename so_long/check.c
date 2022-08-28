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
		if (ft_strlen(lines[i++]) != game->map_width)
			exit(1);// error
	}
	game->map_height = i;	
}
