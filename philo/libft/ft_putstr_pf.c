/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:54:48 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 20:12:08 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_pf(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		str = "(null)";
	while (str[i] != '\0')
	{
		ft_putchar_pf(str[i]);
		i++;
	}
	return (i);
}
