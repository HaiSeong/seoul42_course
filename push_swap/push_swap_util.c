/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:36:34 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/27 15:01:16 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	ft_atolli_error(t_dc_list **a)
{
	ft_dc_lstclear(a);
	ft_error();
	exit(1);
}

long long int	ft_atolli(const char *str, t_dc_list **a)
{
	int				i;
	int				sign;
	long long int	sum;

	sum = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0' || !ft_isdigit(str[i]))
		ft_atolli_error(a);
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum *= 10;
		sum += str[i++] - '0';
		if (sum * sign > 2147483647 || sum * sign < -2147483648)
			ft_atolli_error(a);
	}
	if (str[i] != '\0')
		ft_atolli_error(a);
	return (sum * sign);
}

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
