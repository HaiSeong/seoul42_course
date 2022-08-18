/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:43:53 by hajeong           #+#    #+#             */
/*   Updated: 2022/03/15 15:18:02 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*now;
	int		length;

	now = lst;
	if (lst == NULL)
		return (0);
	length = 1;
	while (now->next != NULL)
	{
		length++;
		now = now->next;
	}
	return (length);
}
