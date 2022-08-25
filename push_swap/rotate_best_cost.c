/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_best_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:35:39 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/25 21:35:59 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_best_cost(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	if (cost_info->best_way == 1)
		rotate1(a, b, cost_info);
	else if (cost_info->best_way == 2)
		rotate2(a, b, cost_info);
	else if (cost_info->best_way == 3)
		rotate3(a, b, cost_info);
	else
		rotate4(a, b, cost_info);
}

void	rotate1(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	while (cost_info->ra_cost > 0 && cost_info->rb_cost > 0)
	{
		rr(a, b);
		cost_info->ra_cost--;
		cost_info->rb_cost--;
	}
	while (cost_info->ra_cost > 0)
	{
		ra(a);
		cost_info->ra_cost--;
	}
	while (cost_info->rb_cost > 0)
	{
		rb(b);
		cost_info->rb_cost--;
	}
}

void	rotate2(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	while (cost_info->rra_cost > 0 &&  cost_info->rrb_cost > 0)
	{
		rrr(a, b);
		cost_info->rra_cost--;
		cost_info->rrb_cost--;
	}
	while (cost_info->rra_cost > 0)
	{
		rra(a);		
		cost_info->rra_cost--;
	}
	while (cost_info->rrb_cost > 0)
	{
		rrb(b);
		cost_info->rrb_cost--;
	}
}

void	rotate3(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	while (cost_info->ra_cost > 0)
	{
		ra(a);
		cost_info->ra_cost--;
	}
	while (cost_info->rrb_cost > 0)
	{
		rrb(b);
		cost_info->rrb_cost--;
	}
}

void	rotate4(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	while (cost_info->rra_cost > 0)
	{
		rra(a);
		cost_info->rra_cost--;
	}
	while (cost_info->rb_cost > 0)
	{
		rb(b);
		cost_info->rb_cost--;
	}
}
