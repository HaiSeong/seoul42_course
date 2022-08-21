
#include "push_swap.h"

void ra(t_dc_list **lst)
{
	*lst = (*lst)->right;
}

void rb(t_dc_list **lst)
{
	*lst = (*lst)->right;
}

void rr(t_dc_list **lst_a, t_dc_list **list_b)
{
	ra(lst_a);
	rb(lst_b);
}

