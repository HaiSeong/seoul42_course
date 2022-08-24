/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:35:39 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/24 19:10:16 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	case1(t_dc_list **a, t_dc_list **b)
{
	t_dc_list	*temp;
	t_dc_data	data;
	size_t		sum;

	temp = *a;
	data = (*b)->data;
	sum = 1;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data)
				return (sum);
			if (temp->left->data < data)
				return (sum + 1);
		}
		if (temp->left->data < data && data < temp->data)
			return (sum);
		temp = temp->right;
		sum++;
	}
	return (sum);
}

size_t	case2(t_dc_list **a, t_dc_list **b)
{
	t_dc_list	*temp;
	t_dc_data	data;
	size_t		sum;

	temp = *a;
	data = (*b)->data;
	sum = 1;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data)
				return (sum);
			if (temp->left->data < data)
				return (sum + 1);
		}
		if (temp->left->data < data && data < temp->data)
			return (sum);
		temp = temp->left;
		sum++;
	}
	return (sum);
}

size_t	case3(t_dc_list **a, t_dc_list **b)
{
	t_dc_list	*temp;
	t_dc_data	data;
	size_t		sum;

	temp = *a;
	data = (*b)->right->data;
	sum = 2;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data)
				return (sum);
			if (temp->left->data < data)
				return (sum + 1);
		}
		if (temp->left->data < data && data < temp->data)
			return (sum);
		temp = temp->right;
		sum++;
	}
	return (sum);
}

size_t	case4(t_dc_list **a, t_dc_list **b)
{
	t_dc_list	*temp;
	t_dc_data	data;
	size_t		sum;

	temp = *a;
	data = (*b)->right->data;
	sum = 2;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data)
				return (sum);
			if (temp->left->data < data)
				return (sum + 1);
		}
		if (temp->left->data < data && data < temp->data)
			return (sum);
		temp = temp->left;
		sum++;
	}
	return (sum);
}
