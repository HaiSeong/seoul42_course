/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dc_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:02:05 by hajeong           #+#    #+#             */
/*   Updated: 2022/03/15 15:07:28 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dc_list	*ft_dc_lstnew(size_t data)
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

size_t	ft_dc_lstdel_front(t_dc_list **lst)
{
	t_dc_list	*del;
	size_t		data;

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

// #include <stdio.h>
// int main()
// {
// 	t_dc_list *a;
// 	a = NULL;

// 	t_dc_list *new = ft_dc_lstnew(3);
// 	ft_dc_lstadd_front(&a, new);
// 	printf("%d\n", a->data);
// 	printf("%p\n", a);
// 	printf("left %p\n", a->left);
// 	printf("right %p\n", a->right);

// 	t_dc_list *new1 = ft_dc_lstnew(4);
// 	ft_dc_lstadd_front(&a, new1);
// 	printf("%d\n", a->data);
// 	printf("%p\n", a);
// 	printf("left %p\n", a->left);
// 	printf("right %p\n", a->right);

// 	t_dc_list *new2 = ft_dc_lstnew(5);
// 	ft_dc_lstadd_front(&a, new2);
// 	printf("%d\n", a->data);
// 	printf("%p\n", a);
// 	printf("left %p\n", a->left);
// 	printf("right %p\n", a->right);

// 	t_dc_list *new3 = ft_dc_lstnew(6);
// 	ft_dc_lstadd_front(&a, new3);
// 	printf("%d\n", a->data);
// 	printf("%p\n", a);
// 	printf("left %p\n", a->left);
// 	printf("right %p\n", a->right);

// 	ft_dc_lstdel_front(&a);
// 	printf("%d\n", a->data);
// 	printf("%p\n", a);
// 	printf("left %p\n", a->left);
// 	printf("right %p\n", a->right);

// 	ft_dc_lstdel_front(&a);
// 	printf("%d\n", a->data);
// 	printf("%p\n", a);
// 	printf("left %p\n", a->left);
// 	printf("right %p\n", a->right);

// 	ft_dc_lstdel_front(&a);
// 	printf("%d\n", a->data);
// 	printf("%p\n", a);
// 	printf("left %p\n", a->left);
// 	printf("right %p\n", a->right);

// 	size_t data = ft_dc_lstdel_front(&a);
// 	// printf("%d\n", a->data);
// 	printf("%p\n", a);
// 	printf("%d\n", data);
// 	// printf("left %p\n", a->left);
// 	// printf("right %p\n", a->right);

// 	system("leaks ./a.out");
// }