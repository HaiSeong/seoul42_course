/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:11:24 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 17:16:23 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_dc_list **lst_a, t_dc_list **lst_b)
{
	t_dc_list	*new;
	s_dc_data	data;

	if (*lst_b == NULL)
		return (0);
	data = ft_dc_lstdel_front(lst_b);
	new = ft_dc_lstnew(data);
	if (new == NULL)
		return (-1);
	ft_dc_lstadd_front(lst_a, new);	
	return (0);
}

int	pb(t_dc_list **lst_a, t_dc_list **lst_b)
{
	t_dc_list	*new;
	s_dc_data	data;

	if (*lst_a == NULL)
		return (0);
	data = ft_dc_lstdel_front(lst_a);
	new = ft_dc_lstnew(data);
	if (new == NULL)
		return (-1);
	ft_dc_lstadd_front(lst_b, new);	
	return (0);
}
