/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:10:38 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/24 21:32:08 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void sa(t_dc_list *lst_a)
{
	t_dc_list	*top;
	t_dc_list	*under;
	t_dc_data	temp;

	if (lst_a == NULL || lst_a->right == lst_a)
		return ;
	top = lst_a;
	under = lst_a->right;
	temp = top->data;
	top->data = under->data;
	under->data = temp;
	ft_printf("sa\n");
}

void sb(t_dc_list *lst_b)
{
	t_dc_list	*top;
	t_dc_list	*under;
	t_dc_data	temp;

	if (lst_b == NULL || lst_b->right == lst_b)
		return ;
	top = lst_b;
	under = lst_b->right;
	temp = top->data;
	top->data = under->data;
	under->data = temp;
	ft_printf("sb\n");
}

void ss(t_dc_list *lst_a, t_dc_list *lst_b)
{
	sa(lst_a);
	sb(lst_b);
	ft_printf("ss\n");
}

