/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:11:38 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/28 20:38:54 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include "libft/libft.h"
#include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct  s_game {
    void	*mlx;
    void	*win;
	char	*file;
	char	*map;
	size_t	map_width;
	size_t	map_height;
}               t_game;

char	*read_file(t_game *game);
void	check_lines(t_game *game);

#endif