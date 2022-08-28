/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 15:11:38 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/28 17:24:58 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    void        *mlx;
    void        *win;
}               t_game;

#endif