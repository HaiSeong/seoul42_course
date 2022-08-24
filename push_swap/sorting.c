/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:35:39 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/24 13:41:12 by hajeong          ###   ########.fr       */
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

	if (data1 < data3 && data3 < data2) // 2) | 1 | 3 | 2| : rra -> sa
	{
		rra(a);
		sa(*a);
	}
	else if (data2 < data1 && data1 < data3) // 3) | 2 | 1 | 3| : sa
		sa(*a);
	else if (data2 < data3 && data3 < data1) // 4) | 2 | 3 | 1| : rra
		rra(a);
	else if (data3 < data1 && data1 < data2) // 5) | 3 | 1 | 2| : ra
		ra(a);
	else if (data3 < data2 && data2 < data1) // 6) | 3 | 2 | 1| : ra -> sa
	{
		ra(a);
		sa(*a);
	}
}
