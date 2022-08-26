
### sorting_before.c

<br>

>copy_a : a 스택을 복사하는 함수
- 맨 마지막 노드부터 시작해서 left방향으로 가면서 스택을 복사
- 할당 실패시 a와 copy를 free 하고 exit
- 성공시 복사한 리스트 리턴
``` c
t_dc_list	*copy_a(t_dc_list **a)
{
	t_dc_list	*copy;
	t_dc_list	*temp;
	t_dc_list	*new;

	copy = NULL;
	temp = (*a)->left;
	while (ft_dc_lstsize(copy) < ft_dc_lstsize(*a))
	{
		new = ft_dc_lstnew(temp->data);
		if (new == NULL)
		{
			ft_dc_lstclear(a);
			ft_dc_lstclear(&copy);
			exit(1);
		}
		ft_dc_lstadd_front(&copy, new);
		temp = temp->left;
	}
	return (copy);
}
```

<br>

>bubble_sort : 스택을 버블솔트로 정렬하는 함수
- 자신보다 오른쪽 원소가 작으면 위치를 바꾼다.
- node1 : 비교할 왼쪽 노드
- node1 : 비교할 오른쪽 노드
- end : bubble_sort는 뒤쪽원소가 자리가 정해지므로 마지막 부분은 탐색할 필요가 없다.
``` c
void	bubble_sort(t_dc_list *copy)
{
	t_dc_list	*node1;
	t_dc_list	*node2;
	t_dc_list	*end;
	t_dc_data	temp;

	end = copy->left;
	while (end != copy)
	{
		node1 = copy;
		while (node1 != end)
		{
			node2 = node1->right;
			if (node1->data > node2->data)
			{
				temp = node1->data;
				node1->data = node2->data;
				node2->data = temp;
			}
			node1 = node1->right;
		}
		end = end->left;
	}
}
```

<br>

>check_double : 스택을 중복된 원소가 있나 확인
``` c
void	check_double(t_dc_list **a, t_dc_list **copy)
{
	t_dc_list	*temp;
	size_t		i;

	temp = *copy;
	i = 0;
	while (i < ft_dc_lstsize(*copy) - 1)
	{
		if (temp->data == temp->right->data)
		{
			ft_error();
			ft_dc_lstclear(a);
			ft_dc_lstclear(copy);
			exit(1);
		}
		temp = temp->right;
		i++;
	}
}
```

<br>

>get_small_pivot : 스택을 3등분 했을때 작은 피봇의 값을 구한다.
``` c
t_dc_data	get_small_pivot(t_dc_list *copy)
{
	t_dc_list	*temp;
	size_t		index;
	size_t		i;

	index = ft_dc_lstsize(copy) / 3;
	temp = copy;
	i = 0;
	while (i++ < index)
		temp = temp->right;
	return (temp->data);
}

```

<br>

>get_big_pivot : 스택을 3등분 했을때 큰 피봇의 값을 구한다.
``` c
t_dc_data	get_big_pivot(t_dc_list *copy)
{
	t_dc_list	*temp;
	size_t		index;
	size_t		i;

	index = ft_dc_lstsize(copy) / 3 * 2;
	temp = copy;
	i = 0;
	while (i++ < index)
		temp = temp->right;
	return (temp->data);
}
```