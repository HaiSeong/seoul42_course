
### push_swap.c

<br>

>ft_error : error case일때 에러를 출력하고 -1 리턴
``` c
int ft_error()
{
	ft_printf("Error\n");
	return (-1);
}
```

<br>

>ft_free_strs : 문자열을 free하는 함수
``` c
static void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}
```

<br>

>make_a : 문자열 배열을 숫자로 바꿔 a스택에 넣는 함수
- 문자열에 이상이 있는 경우 또는 ft_dc_lstnew가 할당 실패시 -1을 리턴 ((strs[i][j] == '-' && ft_strlen(strs[i]) != 1) : "-" 인 경우)
- 정상적으로 종료되면 0을 리턴
``` c
static int	make_a(t_dc_list **a, char **strs, int end)
{
	int i;
	int j;
	t_dc_list	*temp;

	i = 0;
	while (strs[i] != NULL)
		i++;
	while (i-- > end)	//	반복문을 돌면서 하나씩 숫자로 만들어 스택에 추가 한다. (뒤부터 넣어야 방향이 맞음)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			if (!(ft_isdigit(strs[i][j])
				|| (strs[i][j] == '-' && ft_strlen(strs[i]) != 1)))
				return (-1);	//	한글자씩 읽으며 숫자나 - 가 아닌경우 에러
			j++;
		}
		temp = ft_dc_lstnew(ft_atolli(strs[i]));	//	문자열을 숫자로 바꿔 새로운 노드 생성
		if (temp == NULL)	//	할당 실패시
			return (-1);
		ft_dc_lstadd_front(a, temp);	// 스택에 저장
	}
	return (0);
}
```

<br>

>argv_to_stack : argv를 stack으로 만들어줌
- "" 로 둘러쌓인 경우 : split으로 공백을 기준으로 strs를 만든후 strs를 make_a함수로 stack을 만듬, 후에 strs는 free해줌
- 공백으로만 이뤄진 경우 : argv를 바로 stack으로 만듬
- *a == NULL인 경우 : lstnew 할당에 실패해서 make_a에서 a를 모두 지워준 경우
``` c
static void	argv_to_stack(t_dc_list **a, int argc, char *argv[])
{
	char	**strs;

	if (argc < 2)
	{
		ft_error();
		exit(1);
	}
	*a = NULL;
	if (ft_strchr(argv[1], ' ') || ft_strchr(argv[1], '\t')
		|| ft_strchr(argv[1], '\n') || ft_strchr(argv[1], '\v')
		|| ft_strchr(argv[1], '\f') || ft_strchr(argv[1], '\r'))
	{
		strs = ft_split_isspace(argv[1]);
		if (make_a(a, strs, 0) == -1 || argc != 2)	// "" 인경우 인자가 두개이상 들어오면 오류
		{
			ft_dc_lstclear(a);
			ft_error();
			exit(1);
		}
		ft_free_strs(strs);
	}
	else
		make_a(a, argv, 1);
	if (*a == NULL)
		exit(1);
}
```

<br>

>main : 메인함수
- 인자 2개 : sort2함수만 실행
- 인자 3개 : 조건문에 들어가지만 move_all_b함수 안에서 while문에 들어가지 못하고 종료
- 3개 이상 : 리스트 복사
``` c
int	main(int argc, char *argv[])
{
	t_dc_list	*a;
	t_dc_list	*b;
	t_dc_list	*copy;
	t_cost_info	cost_info;

	argv_to_stack(&a, argc, argv);	// argv배열을 a스택으로 변환한다.
	if (ft_dc_lstsize(a) >= 3)
	{
		copy = copy_a(a);	// a 를 copy에 복사한다.
		bubble_sort(&copy);	// copy를 버블정렬로 정렬한다.
		move_all_b(&a, &b, &copy, ft_dc_lstsize(copy) / 3 * 2);	// 3개를 제외하고 b스택으로 모두 옮긴다.
		sort3(&a);	// 남은 3데이터를 정리한다.
		while (b != NULL)	// b가 빌때까지
		{
			cost_info = get_best_cost(&a, &b);		// 최적의 방법과 비용을 구한다.
			rotate_best_cost(&a, &b, &cost_info);	// 그 방법으로 스택을 돌린다.
			pa(&a, &b);	//	b의 원소를 a로 넘긴다.
		}
		organize_stack(&a);	//	a를 돌려 정렬한다.
		ft_dc_lstclear(&copy);	//	복사한 리스트를 free한다.
	}
	else if (ft_dc_lstsize(a) == 2)
		sort2(&a);
	ft_dc_lstclear(&a);	//	a도 free한다.
}
```

<br>