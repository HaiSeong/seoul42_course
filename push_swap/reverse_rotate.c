
#include "push_swap.h"

void rra(t_dc_list **lst)
{
	*lst = (*lst)->left;
}

void rrb(t_dc_list **lst)
{
	*lst = (*lst)->left;
}

void rrr(t_dc_list **lst_a, t_dc_list **lst_b)
{
	ra(lst_a);
	rb(lst_b);
}

