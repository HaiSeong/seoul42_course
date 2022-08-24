/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_circular_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:10:43 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/24 21:05:33 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dc_list	*ft_dc_lstnew(t_dc_data data)
{
	t_dc_list	*new;

	new = (t_dc_list *)malloc(sizeof(t_dc_list));
	if (new == NULL)
		return (0);
	new->data = data;
	new->left = new;
	new->right = new;
	return (new);
}

void	ft_dc_lstadd_front(t_dc_list **lst, t_dc_list *new)
{
	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	new->right = *lst;
	new->left = (*lst)->left;
	(*lst)->left->right = new;
	(*lst)->left = new;
	*lst = new;
}

t_dc_data	ft_dc_lstdel_front(t_dc_list **lst)
{
	t_dc_list	*del;
	t_dc_data	data;

	if ((*lst)->right == (*lst))
	{
		data = (*lst)->data;
		free(*lst);
		*lst = NULL;
		return (data);
	}
	del = *lst;
	*lst = (*lst)->right;
	(*lst)->left->left->right = *lst;
	(*lst)->left = (*lst)->left->left;
	data = del->data;
	free(del);
	return (data);
}

size_t	ft_dc_lstsize(t_dc_list *lst)
{
	t_dc_list	*now;
	t_dc_data	length;

	now = lst;
	if (lst == NULL)
		return (0);
	length = 1;
	while (now->right != lst)
	{
		length++;
		now = now->right;
	}
	return (length);
}

void	ft_dc_lstclear(t_dc_list **lst)
{
	while (*lst != NULL)
		ft_dc_lstdel_front(lst);
}
