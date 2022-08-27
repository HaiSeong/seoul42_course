/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:35:39 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/27 18:53:03 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_dc_list **a)
{
	if ((*a)->data > (*a)->right->data)
	{
		sa(*a);
	}
}

void	sort3(t_dc_list **a)
{
	t_dc_data	data1;
	t_dc_data	data2;
	t_dc_data	data3;

	data1 = (*a)->data;
	data2 = (*a)->right->data;
	data3 = (*a)->right->right->data;
	if (data1 < data3 && data3 < data2)
	{
		rra(a);
		sa(*a);
	}
	else if (data2 < data1 && data1 < data3)
		sa(*a);
	else if (data3 < data1 && data1 < data2)
		rra(a);
	else if (data2 < data3 && data3 < data1)
		ra(a);
	else if (data3 < data2 && data2 < data1)
	{
		ra(a);
		sa(*a);
	}
}

void	move_all_b(t_dc_list **a, t_dc_list **b, t_dc_list **copy, size_t n)
{
	t_dc_data	small_pivot;
	t_dc_data	big_pivot;

	small_pivot = get_small_pivot(*copy);
	big_pivot = get_big_pivot(*copy);
	while (ft_dc_lstsize(*a) > 3)
	{
		if ((*a)->data < small_pivot)
		{
			pb(a, b);
			rb(b);
			n--;
		}
		else if (big_pivot <= (*a)->data)
			ra(a);
		else
		{
			pb(a, b);
			n--;
		}
		if (n == 0)
			while (ft_dc_lstsize(*a) > 3)
				pb(a, b);
	}
}

void	organize_stack(t_dc_list **a)
{
	t_dc_list	*temp;
	size_t		ra_cost;

	temp = *a;
	ra_cost = 0;
	while (temp->left->data < temp->data)
	{
		ra_cost++;
		temp = temp->right;
	}
	if (ra_cost < ft_dc_lstsize(*a) / 2)
	{
		while ((*a)->left->data < (*a)->data)
			ra(a);
	}
	else
	{
		while ((*a)->left->data < (*a)->data)
			rra(a);
	}
}
