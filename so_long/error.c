/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:30:04 by hajeong           #+#    #+#             */
/*   Updated: 2022/09/02 11:30:09 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *error_msg)
{
	ft_printf("Error | %s\n", error_msg);
	exit(1);
}

void	free_buffer_print_error(char *buffer, char *error_msg)
{
	free(buffer);
	print_error(error_msg);
}

void	free_map_print_error(t_game *game, char *error_msg)
{
	free(game->map);
	print_error(error_msg);
}

void	free_map_strs_print_error(t_game *game, char **strs, char *error_msg)
{
	free_strs(strs);
	free_map_print_error(game, error_msg);
}
