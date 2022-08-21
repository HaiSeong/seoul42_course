
#include "push_swap.h"
#include <stdio.h>

void	ft_dc_lst_print(t_dc_list *lst)
{
	t_dc_list	*now;

	now = lst;
	printf("stack : ");
	if (lst == NULL)
		return ; 
	while (now->right != lst)
	{
		printf("%zu ", now->data);
		now = now->right;
	}
	
	printf("%zu\n", now->data);
}

int main()
{
	t_dc_list *a;
	t_dc_list *b;
 	a = NULL;
 	b = NULL;

 	t_dc_list *new = ft_dc_lstnew(3);
 	ft_dc_lstadd_front(&a, new);
 	printf("%zu\n", a->data);
	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
	ft_dc_lst_print(a);

 	t_dc_list *new1 = ft_dc_lstnew(4);
 	ft_dc_lstadd_front(&a, new1);
 	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
	ft_dc_lst_print(a);

	t_dc_list *new2 = ft_dc_lstnew(5);
 	ft_dc_lstadd_front(&a, new2);
 	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

 	t_dc_list *new3 = ft_dc_lstnew(6);
 	ft_dc_lstadd_front(&a, new3);
 	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

	// rotate
	ra(&a);
 	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

	// swap
	printf("\nswap test : ");
	sa(a);
	ft_dc_lst_print(a);
	printf("\n");

	// swap
	printf("\nswap test : ");
	sa(a);
	ft_dc_lst_print(a);
	printf("\n");

	ra(&a);
 	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

	ra(&a);
 	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

	// push
	 
	pb(&a, &b);
	printf("\npush test\n a :\n");
	ft_dc_lst_print(a);
	ft_dc_lst_print(b);
	printf(": b \n\n");

 	ft_dc_lstdel_front(&a);
 	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

	// swap
	printf("\nswap test : ");
	sa(a);
	ft_dc_lst_print(a);
	printf("\n");

	// reverse rotate
 	rra(&a);
	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

	// push
	 
	pb(&a, &b);
	printf("\npush test\n a :\n");
	ft_dc_lst_print(a);
	ft_dc_lst_print(b);
	printf(": b \n\n");

	// push
	 
	pa(&a, &b);
	printf("\npush test\n a :\n");
	ft_dc_lst_print(a);
	ft_dc_lst_print(b);
	printf(": b \n\n");

	// push
	 
	pa(&a, &b);
	printf("\npush test\n a :\n");
	ft_dc_lst_print(a);
	ft_dc_lst_print(b);
	printf(": b \n\n");


 	rra(&a);
	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

 	ft_dc_lstdel_front(&a);
 	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
	ft_dc_lst_print(a);

 	ft_dc_lstdel_front(&a);
 	printf("%zu\n", a->data);
 	printf("%p\n", a);
	printf("left %p\n", a->left);
	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

 	rra(&a);
	printf("%zu\n", a->data);
 	printf("%p\n", a);
 	printf("left %p\n", a->left);
 	printf("right %p\n", a->right);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);


 	size_t data = ft_dc_lstdel_front(&a);
 	printf("%p\n", a);
 	printf("%zu\n", data);
 	printf("length = %d\n", ft_dc_lstsize(a));
	ft_dc_lst_print(a);

	// push
	 
	pa(&a, &b);
	printf("\npush test\n a :\n");
	ft_dc_lst_print(a);
	ft_dc_lst_print(b);
	printf(": b \n\n");
 	system("leaks a.out");
}

