/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:26:22 by hajeong           #+#    #+#             */
/*   Updated: 2022/09/10 12:22:35 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	print_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

static void	sned_chr(char chr, pid_t pid)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (chr >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else if (bit == 1)
			kill(pid, SIGUSR2);
		usleep(30);
		i--;
	}
}

static void	sned_str(char *str, pid_t pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		sned_chr(str[i], pid);
		usleep(300);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
		print_error("Wrong Arguments!");
	pid = ft_atoi(argv[1]);
	if (pid < 101 || pid > 99998)
		print_error("Invalid PID check again!");
	str = ft_strjoin(argv[2], "\n");
	if (str == NULL)
		print_error("System Error!");
	sned_str(str, pid);
}
