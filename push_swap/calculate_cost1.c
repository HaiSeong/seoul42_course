/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_calculate_cost1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:35:39 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/25 21:31:34 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_ra_cost(t_dc_list **a, t_dc_data data)
{
	t_dc_list	*temp;
	size_t		ra_cost;

	temp = *a;
	ra_cost = 0;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data || temp->left->data < data)
				break ;
		}
		if (temp->left->data < data && data < temp->data)
			break ;
		temp = temp->right;
		ra_cost++;
	}
	return (ra_cost);
}

void	set_cost_info_a(t_cost_info *cost_info, size_t ra_cost, t_dc_list *a)
{
	cost_info->ra_cost = ra_cost;
	cost_info->rra_cost = ft_dc_lstsize(a) - ra_cost;
}

void	set_cost_info_b(t_cost_info *cost_info, size_t rb_cost, t_dc_list *b)
{
	cost_info->rb_cost = rb_cost;
	cost_info->rrb_cost = ft_dc_lstsize(b) - rb_cost;
}
