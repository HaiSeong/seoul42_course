
### rotate_best_cost.c 

<br>

>rotate_best_cost : 구한 방법대로 rotate@ 함수를 실행한다.
``` c
void	rotate_best_cost(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	if (cost_info->best_way == 1)
		rotate1(a, b, cost_info);
	else if (cost_info->best_way == 2)
		rotate2(a, b, cost_info);
	else if (cost_info->best_way == 3)
		rotate3(a, b, cost_info);
	else
		rotate4(a, b, cost_info);
}
```

<br>

>rotate1 : ra외 rb를 사용하는 방법
- 중복되는 횟수만큼 rr을 실행한다.
``` c
void	rotate1(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	while (cost_info->ra_cost > 0 && cost_info->rb_cost > 0)
	{
		rr(a, b);
		cost_info->ra_cost--;
		cost_info->rb_cost--;
	}
	while (cost_info->ra_cost > 0)
	{
		ra(a);
		cost_info->ra_cost--;
	}
	while (cost_info->rb_cost > 0)
	{
		rb(b);
		cost_info->rb_cost--;
	}
}
```

<br>

>rotate2 : rra외 rrb를 사용하는 방법
- 중복되는 횟수만큼 rrr을 실행한다.
``` c
void	rotate2(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	while (cost_info->rra_cost > 0 && cost_info->rrb_cost > 0)
	{
		rrr(a, b);
		cost_info->rra_cost--;
		cost_info->rrb_cost--;
	}
	while (cost_info->rra_cost > 0)
	{
		rra(a);
		cost_info->rra_cost--;
	}
	while (cost_info->rrb_cost > 0)
	{
		rrb(b);
		cost_info->rrb_cost--;
	}
}
```

<br>

>rotate3 : ra외 rrb를 사용하는 방법
``` c
void	rotate3(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	while (cost_info->ra_cost > 0)
	{
		ra(a);
		cost_info->ra_cost--;
	}
	while (cost_info->rrb_cost > 0)
	{
		rrb(b);
		cost_info->rrb_cost--;
	}
}
```

<br>

>rotate4 : rra외 rb를 사용하는 방법
``` c
void	rotate4(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info)
{
	while (cost_info->rra_cost > 0)
	{
		rra(a);
		cost_info->rra_cost--;
	}
	while (cost_info->rb_cost > 0)
	{
		rb(b);
		cost_info->rb_cost--;
	}
}
```

<br>
