### 해결 전략

1. Stack a 에 있는 원소	들을 피벗 2개를 설정해서 b로 모두 옮김 (3분할) (2, 3 개는 남긴다.)
- 피벗 2개 구하기, 원소 갯수 구하기
- 중간 값 원소 : pb
- 작은 값 원소 : pb -> rb
- 큰값 원소 : ra
- 원소 갯수만큼 했으면 나머지 pb로 다 넘김
2. Stack b에서 a로 옮기는 과정 : b의 가장 위의 원소가 a에 들어갈 곳을 찾음 : (a를 돌리면서 위로 돌리는 방법과 아래로 돌리는 방법중 작은것을 선택)
+ (b 위에서 2번째 원소의 위 아래 돌리는 방법도 비교)
3. 가장 작은 값을 가진 경우를 찾아 돌림 
4. pa로 삽입

<br>

| 명령어 | a | b |
|:--:|:--|:--|
|	|5 4 3 2 1	|		|
|ra	|4 3 2 1 5	|		|
|ra	|3 2 1 5 4	|		|
|pb	|2 1 5 4	|3		|<- 3
|pb	|1 5 4		|2 3	|<- 2
|pb	|5 4		|1 2 3	|<- 1
|rb	|5 4		|2 3 1	|
|sa	|4 5		|2 3 1	|
|pa	|2 4 5		|3 1	|
|ra	|4 5 2		|3 1	|
|pa	|3 4 5 2 	|1		|
|rra|2 3 4 5	|1		|
|pa	|1 2 3 4 5	|		|


<br>

### sorting.c

<br>

>sort2 : 2개의 원소일때 정렬하는 함수
- 자신보다 오른쪽 원소가 작으면 위치를 바꾼다.
``` c
void	sort2(t_dc_list *a)
{
	if (a->data > a->right->data)
	{
		sa(a);
	}
}
```

<br>

>sort3 : 3개의 원소일때 정렬하는 함수 (s | m | b 로 만들어야함)
   | 1 | 2 | 3 | data
1) | s | m | b | : 그대로
2) | s | b | m | : rra -> sa
3) | m | s | b | : sa
4) | m | b | s | : rra
5) | b | s | m | : ra
6) | b | m | s | : ra -> sa

``` c
void	sort2(t_dc_list *a)
{
	if (a->data > a->right->data)
	{
		sa(a);
	}
}
```

<br>

>move_all_b : 3개만 빼고 모두 b로 넘긴다.
- top_a < small_pivot : b의 아래쪽에 저장 -> pb, rb
- small_pivot <= top_a < big_pivot : b의 위쪽에 저장 -> pb
- big_pivot <= top_a : a에 남기기 -> ra

- n : big_pivot보다 작은 숫자의 갯수 (b로 넘겨얄 숫자들의 갯수 = big_pivot의 인덱스)

``` c
void	move_all_b(t_dc_list **a, t_dc_list **b, t_dc_list **copy, size_t n)
{
	t_dc_data	small_pivot;
	t_dc_data	big_pivot;

	small_pivot = get_small_pivot(*copy);
	big_pivot = get_big_pivot(*copy);
	while (ft_dc_lstsize(*a) > 3)
	{
		if ((*a)->data < small_pivot)
		{
			pb(a, b);
			rb(b);
			n--;
		}
		else if (big_pivot <= (*a)->data)
			ra(a);
		else
		{
			pb(a, b);
			n--;
		}
		if (n == 0)
			while (ft_dc_lstsize(*a) > 3)
				pb(a, b);
	}
}
```

<br>

>push_a : a스택으로 하나씩 옮기는 함수
- get_min_case의 결과를 받아서 최적의 do_push함수를 실행

``` c
```

<br>