/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_before.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:35:39 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/24 13:17:36 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dc_list	*copy_a(t_dc_list **a)
{
	t_dc_list	*copy;
	t_dc_list	*temp;
	t_dc_list	*new;

	copy = NULL;
	temp = (*a)->left;
	while (ft_dc_lstsize(copy) < ft_dc_lstsize(*a))
	{
		new = ft_dc_lstnew(temp->data);
		if (new == NULL)
		{
			ft_dc_lstclear(a);
			ft_dc_lstclear(&copy);
			exit(1);
		}
		ft_dc_lstadd_front(&copy, new);
		temp = temp->left;
	}
	return (copy);
}

void	bubble_sort(t_dc_list *copy)
{
	t_dc_list	*node1;
	t_dc_list	*node2;
	t_dc_list	*end;
	t_dc_data	temp;

	end = copy->left;
	while (end != copy)
	{
		node1 = copy;
		while (node1 != end)
		{
			node2 = node1->right;
			if (node1->data > node2->data)
			{
				temp = node1->data;
				node1->data = node2->data;
				node2->data = temp;
			}
			node1 = node1->right;
		}
		end = end->left;
	}
}

t_dc_data	get_small_pivot(t_dc_list *copy)
{
	t_dc_list	*temp;
	size_t		index;
	size_t		i;

	index = ft_dc_lstsize(copy) / 3;
	temp = copy;
	i = 0;
	while (i++ < index)
		temp = temp->right;
	return (temp->data);
}

t_dc_data	get_big_pivot(t_dc_list *copy)
{
	t_dc_list	*temp;
	size_t		index;
	size_t		i;

	index = ft_dc_lstsize(copy) / 3 * 2;
	temp = copy;
	i = 0;
	while (i++ < index)
		temp = temp->right;
	return (temp->data);
}
