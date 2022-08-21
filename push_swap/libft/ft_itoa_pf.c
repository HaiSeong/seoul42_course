/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:54:58 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 20:12:10 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	count(long n)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static void	putnbr(long n)
{
	if (n > 9)
		putnbr(n / 10);
	ft_putchar_pf(n % 10 + '0');
}

int	ft_itoa_pf(int n)
{
	long	l;
	int		size;

	size = 0;
	l = n;
	if (l < 0)
	{
		ft_putchar_pf('-');
		l *= -1;
		size += 1;
	}
	size += count(l);
	putnbr(l);
	return (size);
}

int	ft_uitoa_pf(int n)
{
	unsigned int	u;
	int				size;

	size = 0;
	u = (unsigned int)n;
	size += count(u);
	putnbr(u);
	return (size);
}
