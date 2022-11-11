/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:58:29 by hajeong           #+#    #+#             */
/*   Updated: 2022/03/14 14:48:18 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*dst_now;
	t_list	*src_now;
	int		size;
	int		i;

	size = ft_lstsize(lst);
	src_now = lst;
	result = ft_lstnew(f(src_now->content));
	dst_now = result;
	i = 0;
	while (i++ < size - 1)
	{
		src_now = src_now->next;
		dst_now->next = ft_lstnew(f(src_now->content));
		if (i != size && dst_now->next == NULL)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		dst_now = dst_now->next;
	}
	return (result);
}
