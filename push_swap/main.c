
#include "push_swap.h"
#include <stdio.h>

int ft_error()
{
	printf("Error\n");
	return (-1);
}


void	ft_dc_lst_print(t_dc_list *lst)
{
	t_dc_list	*now;

	now = lst;
	printf("stack : ");
	if (lst == NULL)
		return ; 
	while (now->right != lst)
	{
		printf("%lld ", now->data);
		now = now->right;
	}
	
	printf("%lld\n", now->data);
}

int main()
{
	t_dc_list *a;
	t_dc_list *b;
 	a = NULL;
 	b = NULL;
 	int i = 0;

	for(i = 150; i>100; i--)
	{
		ft_dc_lstadd_front(&a, ft_dc_lstnew(i));
	}
	for(i = 50; i>0; i--)
	{
		ft_dc_lstadd_front(&a, ft_dc_lstnew(i));
	}
	
	for(i = 100; i>50; i--)
	{
		ft_dc_lstadd_front(&a, ft_dc_lstnew(i));
	}
	for(i = 200; i>150; i--)
	{
		ft_dc_lstadd_front(&a, ft_dc_lstnew(i));
	}
	
	ft_dc_lst_print(a);


 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(331123));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(1223));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(-11231123));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(-113));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(-1123));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(123452351));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(999991));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(34234));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(31234));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(33321));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(33));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(30));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);
 	
 	// ft_dc_lstadd_front(&a, ft_dc_lstnew(90));
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);

 	// t_dc_list *new = ft_dc_lstnew(3);
 	// ft_dc_lstadd_front(&a, new);
 	// printf("%lld\n", a->data);
	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);

 	// t_dc_list *new1 = ft_dc_lstnew(4);
 	// ft_dc_lstadd_front(&a, new1);
 	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);

	// t_dc_list *new2 = ft_dc_lstnew(5);
 	// ft_dc_lstadd_front(&a, new2);
 	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);

 	// t_dc_list *new3 = ft_dc_lstnew(6);
 	// ft_dc_lstadd_front(&a, new3);
 	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);


	//	copy test
	printf("\n\n\ncopy test !!!!\n");
	t_dc_list *copy = copy_a(a);
	ft_dc_lst_print(copy);
	printf("\n");

	// bubble test
	printf("\n\n\nbubble test !!!!\n");
	bubble_sort(copy);
	ft_dc_lst_print(copy);
	printf("\n");

	// pivot test 
	printf("\n\npibot test !!!!\n");
	printf("small pibot : %lld\n", get_small_pivot(copy));
	printf("big pibot : %lld\n", get_big_pivot(copy));
	printf("\n");

	//	move test
	printf("\n\n\nmove test !!!!\n");
	move_all_b(&a, &b, &copy, ft_dc_lstsize(copy) / 3 * 2);
	ft_dc_lst_print(a);
	ft_dc_lst_print(b);

	// sort test
	sort3(&a);
	printf("\n\n\nsorted \n");
	ft_dc_lst_print(a);

	// case test
	size_t c1 = case1(&a, &b);
	size_t c2 = case2(&a, &b);
	size_t c3 = case3(&a, &b);
	size_t c4 = case4(&a, &b);
	printf("\n\n\n\ncase1 = %zd\n", c1);
	printf("case2 = %zd\n", c2);
	printf("case3 = %zd\n", c3);
	printf("case4 = %zd\n", c4);

	
	
	for(i = 0; i<197; i++)
	{
		ft_dc_lstdel_front(&b);
	}
	for(i = 0; i<3; i++)
	{
		ft_dc_lstdel_front(&a);
	}

	// // rotate
	// ra(&a);
 	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);

	// // swap
	// printf("\nswap test : ");
	// sa(a);
	// ft_dc_lst_print(a);
	// printf("\n");

	// // swap
	// printf("\nswap test : ");
	// sa(a);
	// ft_dc_lst_print(a);
	// printf("\n");

	// ra(&a);
 	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);

	// ra(&a);
 	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);

	// // push  
	 
	// pb(&a, &b);
	// printf("\npush test\n a :\n");
	// ft_dc_lst_print(a);
	// ft_dc_lst_print(b);
	// printf(": b \n\n");

 	// ft_dc_lstdel_front(&a);
 	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);

	// // swap
	// printf("\nswap test : ");
	// sa(a);
	// ft_dc_lst_print(a);
	// printf("\n");

	// // reverse rotate
 	// rra(&a);
	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);



	// // push
	 
	// pb(&a, &b);
	// printf("\npush test\n a :\n");
	// ft_dc_lst_print(a);
	// ft_dc_lst_print(b);
	// printf(": b \n\n");

	// // push
	 
	// pa(&a, &b);
	// printf("\npush test\n a :\n");
	// ft_dc_lst_print(a);
	// ft_dc_lst_print(b);
	// printf(": b \n\n");

	// // push
	 
	// pa(&a, &b);
	// printf("\npush test\n a :\n");
	// ft_dc_lst_print(a);
	// ft_dc_lst_print(b);
	// printf(": b \n\n");


 	// rra(&a);
	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);

 	// ft_dc_lstdel_front(&a);
 	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
	// ft_dc_lst_print(a);

 	// ft_dc_lstdel_front(&a);
 	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
	// printf("left %p\n", a->left);
	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);

 	// rra(&a);
	// printf("%lld\n", a->data);
 	// printf("%p\n", a);
 	// printf("left %p\n", a->left);
 	// printf("right %p\n", a->right);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);


 	// t_dc_data data = ft_dc_lstdel_front(&a);
 	// printf("%p\n", a);
 	// printf("%lld\n", data);
 	// printf("length = %zu\n", ft_dc_lstsize(a));
	// ft_dc_lst_print(a);

	// // push
	 
	// pa(&a, &b);
	// printf("\npush test\n a :\n");
	// ft_dc_lst_print(a);
	// ft_dc_lst_print(b);
	// printf(": b \n\n");



 	// system("leaks a.out");
}

