/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:24:25 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 20:21:05 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 42

static char	*ft_join_and_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

static char	*ft_next(char *str, char **line)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		next = NULL;
	else
	{
		next = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
		if (next == NULL)
		{
			*line = NULL;
			free(*line);
		}
		i++;
		j = 0;
		while (str[i] != 0 && next != NULL)
			next[j++] = str[i++];
	}
	free(str);
	return (next);
}

static char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] != '\0' && str[i] != '\n' && line != NULL)
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n' && line != NULL)
		line[i] = '\n';
	return (line);
}

static char	*read_file(int fd, char *str)
{
	char	*buffer;
	int		byte_read;

	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0 && str != NULL)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		str = ft_join_and_free(str, buffer);
		if (ft_strchr(buffer, '\n') > 0)
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	str = read_file(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	if (line == NULL && str[0])
		return (NULL);
	str = ft_next(str, &line);
	if (!line)
		return (NULL);
	return (line);
}
