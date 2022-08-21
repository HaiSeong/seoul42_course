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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_dc_list
{
	struct s_dc_list	*left;
	size_t				data;
	struct s_dc_list	*right;
}	t_dc_list;

t_dc_list	*ft_dc_lstnew(size_t data);
void	ft_dc_lstadd_front(t_dc_list **lst, t_dc_list *new);
size_t	ft_dc_lstdel_front(t_dc_list **lst);
int	ft_dc_lstsize(t_dc_list *lst);
void ra(t_dc_list **lst);
void rb(t_dc_list **lst);
void rr(t_dc_list **lst_a, t_dc_list **list_b);
#endif
