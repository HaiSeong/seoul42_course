
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

>case4 : b의 두번째 원소가 들어갈 곳을 left방향으로 탐색
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

>get_min_case : 4가지중 가장 비용이 작은 케이스 번호를 리턴
``` c
int		get_min_case(t_dc_list **a, t_dc_list **b)
{
	size_t	sums[4];
	size_t	min_sum;
	int		min_idx;
	int		i;

	sums[0] = case1(a, b);
	sums[1] = case2(a, b);
	sums[2] = case3(a, b);
	sums[3] = case4(a, b);
	min_sum = sums[0];
	min_idx = 0;
	i = 1;
	while (i < 4)
	{
		if (min_sum > sums[i])
		{
			min_sum = sums[i];
			min_idx = i;			
		}
	}
	return (min_idx);
}
```

<br>
