/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:37:40 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/28 20:11:24 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static char	*join_and_free(char *map, char *buf)
{
	char	*temp;

	temp = ft_strjoin(map, buf);
	free(map);
	return (temp);
}

char	*read_file(t_game *game)
{
	char	*buffer;
	int		byte_read;
	int		fd;

	fd = open(game->file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		game->map = join_and_free(game->map, buffer);
	}
	free(buffer);
	return (game->map);
}
