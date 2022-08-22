/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_isspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:08:08 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/22 14:35:03 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s)
{
	size_t	i;
	size_t	slen;
	size_t	count;

	slen = ft_strlen(s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (!ft_isspace(s[i]) && (ft_isspace(s[i + 1]) || i + 1 == slen))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	make_strs(char **strs, char const *s)
{
	size_t	i;
	size_t	length;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]))
			i++;
		else
		{
			length = 0;
			while (!ft_isspace(s[i + length]) && i + length < ft_strlen(s))
				length++;
			strs[word] = ft_substr(s, i, length);
			if (strs[word] == NULL)
				return (word + 1);
			i += length;
			word++;
		}
	}
	return (0);
}

char	**ft_split_isspace(char const *s)
{
	char	**result;
	size_t	wc;
	size_t	i;
	size_t	malloc_error;

	i = 0;
	wc = word_count(s);
	result = (char **)malloc(sizeof(char *) * (wc + 1));
	if (result == NULL)
		return (0);
	malloc_error = make_strs(result, s);
	if (malloc_error != 0)
	{
		while (i < malloc_error)
			free (result[i++]);
		free(result);
		return (0);
	}
	result[wc] = 0;
	return (result);
}
