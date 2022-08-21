
#include "push_swap.h"

int	pa(t_dc_list **lst_a, t_dc_list **lst_b)
{
	t_dc_list	*new;
	size_t		data;

	if (*lst_b == NULL)
		return (0);
	data = ft_dc_lstdel_front(lst_b);
	new = ft_dc_lstnew(data);
	if (new == NULL)
		return (-1);
	ft_dc_lstadd_front(lst_a, new);	
	return (0);
}

int	pb(t_dc_list **lst_a, t_dc_list **lst_b)
{
	t_dc_list	*new;
	size_t		data;

	if (*lst_a == NULL)
		return (0);
	data = ft_dc_lstdel_front(lst_a);
	new = ft_dc_lstnew(data);
	if (new == NULL)
		return (-1);
	ft_dc_lstadd_front(lst_b, new);	
	return (0);
}
