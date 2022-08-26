
### calculate_cost1.c

<br>

>get_ra_cost : data가 a에 들어가기 위해서 ra를 몇번 써야할지 구하는 함수
- (temp->left->data > temp->data), (data < temp->data || temp->left->data < data) : <br>data=6 이고 a = [3 4 5 1 2] 일때 6은 5와 1 사이에 넣어야 한다. <br>같은 경우로 data=0인 경우또한 5와 1사이에 넣어야한다. 
- (temp->left->data < data && data < temp->data) : 사이에 넣는 경우
``` c
size_t	get_ra_cost(t_dc_list **a, t_dc_data data)
{
	t_dc_list	*temp;
	size_t		ra_cost;

	temp = *a;
	ra_cost = 0;
	while (temp != (*a)->left)
	{
		if (temp->left->data > temp->data)
		{
			if (data < temp->data || temp->left->data < data)
				break ;
		}
		if (temp->left->data < data && data < temp->data)
			break ;
		temp = temp->right;
		ra_cost++;
	}
	return (ra_cost);
}
```

<br>

>set_cost_info_a : ra_cost와 rra_cost를 cost_info에 저장한다.
- rra_cost는 a의 lstsize 에서 ra_cost를 빼서 구한다.
``` c
void	set_cost_info_a(t_cost_info *cost_info, size_t ra_cost, t_dc_list *a)
{
	cost_info->ra_cost = ra_cost;
	cost_info->rra_cost = ft_dc_lstsize(a) - ra_cost;
}
```

<br>

>set_cost_info_b : rb_cost와 rrb_cost를 cost_info에 저장한다.
- rrb_cost는 b의 lstsize 에서 rb_cost를 빼서 구한다.
``` c
void	set_cost_info_b(t_cost_info *cost_info, size_t rb_cost, t_dc_list *b)
{
	cost_info->rb_cost = rb_cost;
	cost_info->rrb_cost = ft_dc_lstsize(b) - rb_cost;
}
```

<br>

### calculate_cost2.c

<br>

>cal_sum_cost1 : pa하기 전 상태로 만드는 비용을 계산해준다.
- 방법 1 : ra와 rb를 사용하는 방법
- 방법 2 : rra와 rrb를 사용하는 방법
- 예를 들어 ra연산과 rb연산 중에 ra연산이 더 크다면 rr연산을 rb번 하고 ra연산을 (ra-rb)번 한다. <br>결국 연산의 합은 ra번 이다. 따라서 ra와 rb중 큰값을 고르면 된다.
- min_sum과 best_way는 각각 최적의 연산 횟수와 최고의 방법이다. min_sum이 변경되면 best_way도 갱신해준다.
``` c
void	cal_sum_cost1(t_cost_info *cost_info, t_dc_list *a, t_dc_list *b)
{
	size_t	min_sum;

	cost_info->best_way = 1;
	if (cost_info->ra_cost > cost_info->rb_cost)
		min_sum = cost_info->ra_cost;
	else
		min_sum = cost_info->rb_cost;
	if (cost_info->rra_cost > cost_info->rrb_cost)
	{
		if (cost_info->rra_cost < min_sum)
		{
			min_sum = cost_info->rra_cost;
			cost_info->best_way = 2;
		}
	}
	else
	{
		if (cost_info->rrb_cost < min_sum)
		{
			min_sum = cost_info->rrb_cost;
			cost_info->best_way = 2;
		}
	}
	cost_info->cost_sum = min_sum;
}
```

<br>

>cal_sum_cost2 : pa하기 전 상태로 만드는 비용을 계산해준다.
- 방법 3 : ra와 rrb를 사용하는 방법
- 방법 4 : rra와 rb를 사용하는 방법
- 두 스택의 돌리는 방향이 다르므로 단순 합을 구해서 계산해준다.
- min_sum과 best_way는 각각 최적의 연산 횟수와 최고의 방법이다. min_sum이 변경되면 best_way도 갱신해준다.
``` c
void	cal_sum_cost2(t_cost_info *cost_info, t_dc_list *a, t_dc_list *b)
{
	size_t	min_sum;

	min_sum = cost_info->cost_sum;
	if (min_sum > cost_info->ra_cost + cost_info->rrb_cost)
	{
		min_sum = cost_info->ra_cost + cost_info->rrb_cost;
		cost_info->best_way = 3;
	}
	if (min_sum > cost_info->rra_cost + cost_info->rb_cost)
	{
		min_sum = cost_info->rra_cost + cost_info->rb_cost;
		cost_info->best_way = 4;
	}
	cost_info->cost_sum = min_sum;
}
```

<br>

>get_best_cost : b에 있는 데이터 하나를 알맞은 자리에 pa하기 바로 전 상태로 만드는 최적의 비용, 방법을 구한다.
- b를 하나씩 돌려보면서 b 가장위에 있는 원소가 넘어가기 위한 최소비용을 찾는다.
- temp_info : 임시로 정보를 받을 구조체 변수
- best_info : 최적의 비용과 방법을 저장할 구조체 변수
- best_info.cost_sum > temp_info.cost_sum 이면 best_info를 갱신한다.
``` c
t_cost_info	get_best_cost(t_dc_list **a, t_dc_list **b)
{
	t_cost_info	temp_info;
	t_cost_info	best_info;
	t_dc_list	*temp;
	size_t		rb_cost;

	best_info.cost_sum = ft_dc_lstsize(*a) + ft_dc_lstsize(*b);
	temp = *b;
	rb_cost = 0;
	while (rb_cost < ft_dc_lstsize(*b))
	{
		set_cost_info_a(&temp_info, get_ra_cost(a, temp->data), *a);
		set_cost_info_b(&temp_info, rb_cost, *b);
		cal_sum_cost1(&temp_info, *a, *b);
		cal_sum_cost2(&temp_info, *a, *b);
		if (best_info.cost_sum > temp_info.cost_sum)
		{
			set_cost_info_a(&best_info, temp_info.ra_cost, *a);
			set_cost_info_b(&best_info, temp_info.rb_cost, *b);
			best_info.cost_sum = temp_info.cost_sum;
			best_info.best_way = temp_info.best_way;
		}
		temp = temp->right;
		rb_cost++;
	}
	return (best_info);
}
```
