/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:08:08 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 19:55:00 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	slen;
	size_t	count;

	slen = ft_strlen(s);
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || i + 1 == slen))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	make_strs(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	length;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			length = 0;
			while (s[i + length] != c && i + length < ft_strlen(s))
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

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	wc;
	size_t	i;
	size_t	malloc_error;

	i = 0;
	wc = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (wc + 1));
	if (result == NULL)
		return (0);
	malloc_error = make_strs(result, s, c);
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
