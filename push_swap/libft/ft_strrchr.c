/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:31:08 by hajeong           #+#    #+#             */
/*   Updated: 2022/03/12 12:50:41 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	finding;
	char	*temp;
	int		i;

	temp = 0;
	finding = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == finding)
			temp = ((char *)s + i);
		i++;
	}
	if (s[i] == finding)
		return ((char *)s + i);
	return (temp);
}
