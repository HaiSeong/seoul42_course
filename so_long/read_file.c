/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:37:40 by hajeong           #+#    #+#             */
/*   Updated: 2022/09/02 11:34:40 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(t_game *game)
{
	char	*buffer;
	int		byte_read;
	int		fd;

	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		print_error("System error, reboot game");
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			free_buffer_print_error(buffer, "System error, reboot game");
		buffer[byte_read] = '\0';
		game->map = join_and_free(game->map, buffer);
		if (game->map == NULL)
			free_buffer_print_error(buffer, "System error, reboot game");
	}
	free(buffer);
}
