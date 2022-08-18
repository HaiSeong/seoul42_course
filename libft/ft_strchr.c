/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:30:55 by hajeong           #+#    #+#             */
/*   Updated: 2022/03/15 13:44:47 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	finding;
	int		i;

	finding = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == finding)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == finding)
		return ((char *)s + i);
	return (0);
}
