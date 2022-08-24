
### sorting_push_util.c

<br>

>case1 : b의 가장 위의 원소가 들어갈 곳을 right방향으로 탐색
``` c
size_t	case1(t_dc_list **a, t_dc_list **b)
{
	t_dc_list	*temp;
	t_dc_data	data;
	size_t		sum;

	temp = *a;
	data = (*b)->data;
	sum = 1;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data)
				return (sum);
			if (temp->left->data < data)
				return (sum + 1);
		}
		if (temp->left->data < data && data < temp->data)
			return (sum);
		temp = temp->right;
		sum++;
	}
	return (sum);
}
```

<br>

>case2 : b의 가장 위의 원소가 들어갈 곳을 left방향으로 탐색
``` c
size_t	case2(t_dc_list **a, t_dc_list **b)
{
	t_dc_list	*temp;
	t_dc_data	data;
	size_t		sum;

	temp = *a;
	data = (*b)->data;
	sum = 1;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data)
				return (sum);
			if (temp->left->data < data)
				return (sum + 1);
		}
		if (temp->left->data < data && data < temp->data)
			return (sum);
		temp = temp->left;
		sum++;
	}
	return (sum);
}
```

<br>

>case3 : b의 두번째 원소가 들어갈 곳을 right방향으로 탐색
``` c
size_t	case3(t_dc_list **a, t_dc_list **b)
{
	t_dc_list	*temp;
	t_dc_data	data;
	size_t		sum;

	temp = *a;
	data = (*b)->right->data;
	sum = 2;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data)
				return (sum);
			if (temp->left->data < data)
				return (sum + 1);
		}
		if (temp->left->data < data && data < temp->data)
			return (sum);
		temp = temp->right;
		sum++;
	}
	return (sum);
}
```

<br>

>case2 : b의 두번째 원소가 들어갈 곳을 left방향으로 탐색
``` c
size_t	case4(t_dc_list **a, t_dc_list **b)
{
	t_dc_list	*temp;
	t_dc_data	data;
	size_t		sum;

	temp = *a;
	data = (*b)->right->data;
	sum = 2;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data)
				return (sum);
			if (temp->left->data < data)
				return (sum + 1);
		}
		if (temp->left->data < data && data < temp->data)
			return (sum);
		temp = temp->left;
		sum++;
	}
	return (sum);
}
```

<br>
