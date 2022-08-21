
#include "push_swap.h"

void sa(t_dc_list *lst_a)
{
	t_dc_list	*top;
	t_dc_list	*under;
	size_t		temp;

	if (lst_a == NULL || lst_a->right == lst_a)
		return ;
	top = lst_a;
	under = lst_a->right;
	temp = top->data;
	top->data = under->data;
	under->data = temp;
}

void sb(t_dc_list *lst_b)
{
	t_dc_list	*top;
	t_dc_list	*under;
	size_t		temp;

	if (lst_b == NULL || lst_b->right == lst_b)
		return ;
	top = lst_b;
	under = lst_b->right;
	temp = top->data;
	top->data = under->data;
	under->data = temp;
}

void ss(t_dc_list *lst_a, t_dc_list *lst_b)
{
	sa(lst_a);
	sb(lst_b);
}

