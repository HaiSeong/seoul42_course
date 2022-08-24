/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:10:33 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/24 21:31:59 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void rra(t_dc_list **lst)
{
	*lst = (*lst)->left;
	ft_printf("rra\n");
}

void rrb(t_dc_list **lst)
{
	*lst = (*lst)->left;
	ft_printf("rrb\n");
}

void rrr(t_dc_list **lst_a, t_dc_list **lst_b)
{
	ra(lst_a);
	rb(lst_b);
	ft_printf("rrr\n");
}

