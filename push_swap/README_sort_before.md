
### sorting_before.c

<br>

>copy_a : a 스택을 복사하는 함수
- 맨 마지막 노드부터 시작해서 left방향으로 가면서 스택을 복사
- 할당 실패시 NULL 리턴
- 성공시 복사한 리스트 리턴
``` c
t_dc_list	*copy_a(t_dc_list *a)
{
	t_dc_list *copy;	// 복사본
	t_dc_list *temp;
	t_dc_list *new;

	copy = NULL;
	temp = a->left;
	while (temp != a)
	{
		new = ft_dc_lstnew(temp->data);
		if (new == NULL)
			return (NULL);
		ft_dc_lstadd_front(&copy, new);
		temp = temp->left;
	}
	new = ft_dc_lstnew(temp->data);
	if (new == NULL)
		return (NULL);
	ft_dc_lstadd_front(&copy, new);
	return (copy);
}
```

<br>

>bubble_sort : 스택을 버블솔트로 정렬하는 함수
- 자신보다 오른쪽 원소가 작으면 위치를 바꾼다.
``` c

```

<br>