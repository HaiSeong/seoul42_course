/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:08:12 by hajeong           #+#    #+#             */
/*   Updated: 2022/03/12 13:01:54 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	finding;
	unsigned char	*str;

	str = (unsigned char *)s;
	finding = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == finding)
			return ((void *)str + i);
		i++;
	}
	return (0);
}
