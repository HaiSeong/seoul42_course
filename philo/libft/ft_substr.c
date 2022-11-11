/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:56:15 by hajeong           #+#    #+#             */
/*   Updated: 2022/03/15 14:21:02 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	if (start > slen)
	{
		sub = (char *)malloc(sizeof(char));
		sub[0] = '\0';
		return (sub);
	}
	else if (start + len > slen)
		sub = (char *)malloc(slen - start + 2);
	else
		sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (0);
	i = 0;
	while (s[i] != 0 && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
