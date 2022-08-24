/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_do_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:35:39 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/24 20:21:28 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push1(t_dc_list **a, t_dc_list **b)
{
	while (1)
	{
		if ((*a)->left->data > (*a)->data)
		{
			if ((*b)->data < (*a)->data)
			{
				pa(a, b);
				return ;
			}	
			if ((*a)->left->data < (*b)->data)
			{
				pa(a, b);
				ra(a);
				return ;
			}
		}
		if ((*a)->left->data < (*b)->data && (*b)->data < (*a)->data)
		{
			pa(a, b);
			return ;
		}
		ra(a);
	}
	return ;
}

void	do_push2(t_dc_list **a, t_dc_list **b)
{
	while (1)
	{
		if ((*a)->left->data > (*a)->data)
		{
			if ((*b)->data < (*a)->data)
			{
				pa(a, b);
				return ;
			}	
			if ((*a)->left->data < (*b)->data)
			{
				pa(a, b);
				ra(a);
				return ;
			}
		}
		if ((*a)->left->data < (*b)->data && (*b)->data < (*a)->data)
		{
			pa(a, b);
			return ;
		}
		rra(a);
	}
	return ;
}

void	do_push3(t_dc_list **a, t_dc_list **b)
{
	sb(*b);
	while (1)
	{
		if ((*a)->left->data > (*a)->data)
		{
			if ((*b)->data < (*a)->data)
			{
				pa(a, b);
				return ;
			}	
			if ((*a)->left->data < (*b)->data)
			{
				pa(a, b);
				ra(a);
				return ;
			}
		}
		if ((*a)->left->data < (*b)->data && (*b)->data < (*a)->data)
		{
			pa(a, b);
			return ;
		}
		ra(a);
	}
	return ;
}

void	do_push4(t_dc_list **a, t_dc_list **b)
{
	sb(*b);
	while (1)
	{
		if ((*a)->left->data > (*a)->data)
		{
			if ((*b)->data < (*a)->data)
			{
				pa(a, b);
				return ;
			}	
			if ((*a)->left->data < (*b)->data)
			{
				pa(a, b);
				ra(a);
				return ;
			}
		}
		if ((*a)->left->data < (*b)->data && (*b)->data < (*a)->data)
		{
			pa(a, b);
			return ;
		}
		rra(a);
	}
	return ;
}

// size_t	case3(t_dc_list **a, t_dc_list **b)
// {
// 	t_dc_list	*temp;
// 	t_dc_data	data;
// 	size_t		sum;

// 	temp = *a;
// 	data = (*b)->right->data;
// 	sum = 2;
// 	while (temp != (*a)->left)
// 	{
// 		if (temp->left->data > temp->data)
// 		{
// 			if (data < temp->data)
// 				return (sum);
// 			if (temp->left->data < data)
// 				return (sum + 1);
// 		}
// 		if (temp->left->data < data && data < temp->data)
// 			return (sum);
// 		temp = temp->right;
// 		sum++;
// 	}
// 	return (sum);
// }

// size_t	case4(t_dc_list **a, t_dc_list **b)
// {
// 	t_dc_list	*temp;
// 	t_dc_data	data;
// 	size_t		sum;

// 	temp = *a;
// 	data = (*b)->right->data;
// 	sum = 2;
// 	while (temp != (*a)->left)
// 	{
// 		if (temp->left->data > temp->data)
// 		{
// 			if (data < temp->data)
// 				return (sum);
// 			if (temp->left->data < data)
// 				return (sum + 1);
// 		}
// 		if (temp->left->data < data && data < temp->data)
// 			return (sum);
// 		temp = temp->left;
// 		sum++;
// 	}
// 	return (sum);
// }

// int		get_min_case(t_dc_list **a, t_dc_list **b)
// {
// 	size_t	sums[4];
// 	size_t	min_sum;
// 	int		min_idx;
// 	int		i;

// 	sums[0] = case1(a, b);
// 	sums[1] = case2(a, b);
// 	sums[2] = case3(a, b);
// 	sums[3] = case4(a, b);
// 	min_sum = sums[0];
// 	min_idx = 0;
// 	i = 1;
// 	while (i < 4)
// 	{
// 		if (min_sum > sums[i])
// 		{
// 			min_sum = sums[i];
// 			min_idx = i;			
// 		}
// 		i++;
// 	}
// 	return (min_idx + 1);
// }
