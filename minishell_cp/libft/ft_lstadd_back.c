/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 10:56:31 by hajeong           #+#    #+#             */
/*   Updated: 2022/03/15 14:45:09 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*now;

	now = *lst;
	if (now == NULL)
	{
		*lst = new;
		return ;
	}
	while (now->next != NULL)
	{
		now = now->next;
	}
	now->next = new;
}
