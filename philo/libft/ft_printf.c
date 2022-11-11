/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:54:57 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 20:12:07 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checkformat(char c, va_list ap)
{
	unsigned long long	p;

	if (c == 'c')
		return (ft_putchar_pf((char)va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr_pf(va_arg(ap, char *)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex_pf(va_arg(ap, int), c));
	else if (c == '%')
		return (ft_putchar_pf('%'));
	else if (c == 'd' || c == 'i')
		return (ft_itoa_pf(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_uitoa_pf(va_arg(ap, int)));
	else if (c == 'p')
	{
		p = va_arg(ap, unsigned long long);
		if (p == 0)
			return (ft_putstr_pf("0x0"));
		else
			return (ft_putstr_pf("0x") + ft_putpointer_pf(p));
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		sum;

	va_start(ap, str);
	i = 0;
	sum = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				break ;
			sum += checkformat(str[i], ap);
		}
		else
			sum += ft_putchar_pf(str[i]);
		i++;
	}
	va_end(ap);
	return (sum);
}
