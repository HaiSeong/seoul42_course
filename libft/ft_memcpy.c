/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:28:13 by hajeong           #+#    #+#             */
/*   Updated: 2022/03/15 13:43:50 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*char_dst;
	char	*char_src;

	i = 0;
	char_dst = (char *)dst;
	char_src = (char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		char_dst[i] = char_src[i];
		i++;
	}
	return ((void *)char_dst);
}
