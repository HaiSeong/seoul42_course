/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 20:26:20 by hajeong           #+#    #+#             */
/*   Updated: 2022/09/09 20:31:41 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	get_signal(int signal)
{
	static char	chr;
	static int	cnt;

	chr <<= 1;
	cnt++;
	if (signal == SIGUSR2)
		chr |= 1;
	if (cnt == 8)
	{
		ft_putchar_fd(chr, 1);
		cnt = 0;
		chr = 0;
	}
}

int	main(void)
{
	ft_printf("pid: %d\n", getpid());
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	while (1)
		pause();
}
