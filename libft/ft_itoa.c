/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 12:13:00 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 19:54:24 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(int n)
{
	int		length;
	long	n_long;

	length = 0;
	n_long = (long)n;
	if (n_long == 0)
		return (1);
	else if (n_long < 0)
	{
		n_long *= -1;
		length += 1;
	}
	while (n_long)
	{
		n_long /= 10;
		length += 1;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		i;
	long	n_long;
	char	*result;

	i = count_length(n) - 1;
	n_long = (long) n;
	result = (char *)malloc(count_length(n) + 1);
	if (result == NULL)
		return (0);
	if (n_long == 0)
		result[0] = '0';
	else if (n_long < 0)
	{
		result[0] = '-';
		n_long *= -1;
	}
	while (n_long)
	{
		result[i--] = '0' + n_long % 10;
		n_long /= 10;
	}
	result[count_length(n)] = '\0';
	return (result);
}
