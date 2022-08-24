/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:10:35 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/24 21:32:02 by hajeong          ###   ########.fr       */
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

void rr(t_dc_list **lst_a, t_dc_list **lst_b)
{
	ra(lst_a);
	rb(lst_b);
	ft_printf("rr\n");
}

