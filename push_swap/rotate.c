/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:10:35 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 17:10:48 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void ra(t_dc_list **lst)
{
	*lst = (*lst)->right;
}

void rb(t_dc_list **lst)
{
	*lst = (*lst)->right;
}

void rr(t_dc_list **lst_a, t_dc_list **lst_b)
{
	ra(lst_a);
	rb(lst_b);
}

