
### ft_doubly_circular_list.c

<br>

>sa : 스택 a의 가장 위에 있는 두 원소(혹은 첫 번쨰 원소와 두 번째 원소)의 위치를 서로 바꾼다.
``` c
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
}
```

<br>

>pa : 스택 b에서 가장 위(탑)에 있는 원소를 가져와서, 스택 a의 맨 위(탑)에 넣는다.
- 스택 b가 비어 있으면 아무 것도 하지 않는다.
``` c
int	pa(t_dc_list **lst_a, t_dc_list **lst_b)
{
	t_dc_list	*new;
	t_dc_data	data;

	if (*lst_b == NULL)
		return (0);
	data = ft_dc_lstdel_front(lst_b);
	new = ft_dc_lstnew(data);
	if (new == NULL)
		return (-1);
	ft_dc_lstadd_front(lst_a, new);	
	return (0);
}
```

<br>

>ra : 스택 a의 모든 원소들을 위로 1 인덱스 만큼 올린다.
- 첫 번째 원소(탑)는 마지막 원소(바텀)가 된다.
``` c
void ra(t_dc_list **lst)
{
	*lst = (*lst)->right;
}
```

<br>

>rra : 스택 a의 모든 원소들을 아래로 1 인덱스 만큼 내린다.
- 마지막 원소(바텀)는 첫 번째 원소(탑)가 된다.
``` c
void rra(t_dc_list **lst)
{
	*lst = (*lst)->left;
}
```

<br>
