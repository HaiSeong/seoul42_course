/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:52:28 by apple             #+#    #+#             */
/*   Updated: 2022/03/13 17:23:17 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	str = 0;
	start = 0;
	end = ft_strlen(s1);
	if (ft_strlen(s1) == 0)
	{
		str = (char *)malloc(sizeof(char));
		if (str == NULL)
			return (0);
		str[0] = '\0';
		return (str);
	}
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	while (ft_strchr(set, s1[end - 1]) && start < end - 1)
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s1 + start, end - start + 1);
	str[end - start] = '\0';
	return (str);
}
