/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:10:35 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/25 20:34:57 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void ra(t_dc_list **lst)
{
	*lst = (*lst)->right;
	ft_printf("ra\n");
}

void rb(t_dc_list **lst)
{
	*lst = (*lst)->right;
	ft_printf("rb\n");
}

void ra_no_print(t_dc_list **lst)
{
	*lst = (*lst)->right;
}

void rb_no_print(t_dc_list **lst)
{
	*lst = (*lst)->right;
}

void rr(t_dc_list **lst_a, t_dc_list **lst_b)
{
	ra_no_print(lst_a);
	rb_no_print(lst_b);
	ft_printf("rr\n");
}

