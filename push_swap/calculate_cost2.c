/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_calculate_cost2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:31:25 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/25 21:31:42 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cal_sum_cost1(t_cost_info *cost_info)
{
	size_t	min_sum;

	cost_info->best_way = 1;
	if (cost_info->ra_cost > cost_info->rb_cost)
		min_sum = cost_info->ra_cost;
	else
		min_sum = cost_info->rb_cost;
	if (cost_info->rra_cost > cost_info->rrb_cost)
	{
		if (cost_info->rra_cost < min_sum)
		{
			min_sum = cost_info->rra_cost;
			cost_info->best_way = 2;
		}
	}
	else
	{
		if (cost_info->rrb_cost < min_sum)
		{
			min_sum = cost_info->rrb_cost;
			cost_info->best_way = 2;
		}
	}
	cost_info->cost_sum = min_sum;
}

void	cal_sum_cost2(t_cost_info *cost_info)
{
	size_t	min_sum;

	min_sum = cost_info->cost_sum;
	if (min_sum > cost_info->ra_cost + cost_info->rrb_cost)
	{
		min_sum = cost_info->ra_cost + cost_info->rrb_cost;
		cost_info->best_way = 3;
	}
	if (min_sum > cost_info->rra_cost + cost_info->rb_cost)
	{
		min_sum = cost_info->rra_cost + cost_info->rb_cost;
		cost_info->best_way = 4;
	}
	cost_info->cost_sum = min_sum;
}

t_cost_info	get_best_cost(t_dc_list **a, t_dc_list **b)
{
	t_cost_info	temp_info;
	t_cost_info	best_info;
	t_dc_list	*temp;
	size_t		rb_cost;

	best_info.cost_sum = ft_dc_lstsize(*a) + ft_dc_lstsize(*b);
	temp = *b;
	rb_cost = 0;
	while (rb_cost < ft_dc_lstsize(*b))
	{
		set_cost_info_a(&temp_info, get_ra_cost(a, temp->data), *a);
		set_cost_info_b(&temp_info, rb_cost, *b);
		cal_sum_cost1(&temp_info);
		cal_sum_cost2(&temp_info);
		if (best_info.cost_sum > temp_info.cost_sum)
		{
			set_cost_info_a(&best_info, temp_info.ra_cost, *a);
			set_cost_info_b(&best_info, temp_info.rb_cost, *b);
			best_info.cost_sum = temp_info.cost_sum;
			best_info.best_way = temp_info.best_way;
		}
		temp = temp->right;
		rb_cost++;
	}
	return (best_info);
}
