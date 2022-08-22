[그리디 알고리즘 설명](https://techdebt.tistory.com/27) (케이크)
[소스코드](https://github.com/JeonYoungHo-youjeon/push_swap/blob/master/push_swap.h)


### ft_doubly_circular_list.c

<br>

>ft_dc_lstnew : 새로운 노드를 할당하는 함수
- return : 할당받은 노드의 주소 / 할당 실패시 NULL
``` c
t_dc_list	*ft_dc_lstnew(t_dc_data data)
{
	t_dc_list	*new;

	new = (t_dc_list *)malloc(sizeof(t_dc_list));
	if (new == NULL)
		return (0);
	new->data = data;
	new->left = new;
	new->right = new;
	return (new);
}
```

<br>

>ft_dc_lstadd_front : new노드를 lst맨 앞부분에 추가하는 함수
- 비어있는 리스트는 그냥 lst에 new를 대입
``` c
void	ft_dc_lstadd_front(t_dc_list **lst, t_dc_list *new)
{
	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	new->right = *lst;
	new->left = (*lst)->left;
	(*lst)->left->right = new;
	(*lst)->left = new;
	*lst = new;
}
```

<br>

>ft_dc_lstdel_front : lst맨 앞부분의 노드를 삭제하는 함수
- 마지막 노드를 삭제할때는 lst에 NULL을 대입
``` c
t_dc_data	ft_dc_lstdel_front(t_dc_list **lst)
{
	t_dc_list	*del;
	t_dc_data	data;

	if ((*lst)->right == (*lst))
	{
		data = (*lst)->data;
		free(*lst);
		*lst = NULL;
		return (data);
	}
	del = *lst;
	*lst = (*lst)->right;
	(*lst)->left->left->right = *lst;
	(*lst)->left = (*lst)->left->left;
	data = del->data;
	free(del);
	return (data);
}
```

<br>

>ft_dc_lstsize : lst의 길이를 구하는 함수
``` c
size_t	ft_dc_lstsize(t_dc_list *lst)
{
	t_dc_list	*now;
	t_dc_data	length;

	now = lst;
	if (lst == NULL)
		return (0);
	length = 1;
	while (now->right != lst)
	{
		length++;
		now = now->right;
	}
	return (length);
}
```

<br>

>ft_dc_lstclear : lst를 모두 free하는 함수
``` c
void	ft_dc_lstclear(t_dc_list **lst)
{
	while (*lst != NULL)
		ft_dc_lstdel_front(lst);
}
```

<br>
