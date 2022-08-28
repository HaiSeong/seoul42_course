/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:54:51 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 20:12:09 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charcount(unsigned long long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

static void	putnbr_base(unsigned long long nb, char *base)
{
	if (nb >= 16)
		putnbr_base((nb / 16), base);
	ft_putchar_pf(base[nb % 16]);
}

int	ft_puthex_pf(int i, char x)
{
	char			*base;
	int				sum;
	unsigned int	c;

	base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	sum = 0;
	c = (unsigned int)i;
	putnbr_base(c, base);
	sum += charcount(c);
	return (sum);
}

int	ft_putpointer_pf(unsigned long long l)
{
	char	*base;
	int		sum;

	base = "0123456789abcdef";
	sum = 0;
	putnbr_base(l, base);
	sum += charcount(l);
	return (sum);
}
