/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:56:55 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/27 19:02:57 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (-1);
}

void	ft_error_exit(void)
{
	ft_error();
	exit(1);
}

void	ft_error_free_a_exit(t_dc_list **a)
{
	ft_dc_lstclear(a);
	ft_error();
	exit(1);
}

void	ft_error_free_a_copy_exit(t_dc_list **a, t_dc_list **copy)
{
	ft_dc_lstclear(a);
	ft_dc_lstclear(copy);
	ft_error();
	exit(1);
}
