
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
- ft_dc_lstnew가 할당 실패시 스택에 모든 노드를 지우고 -1을 리턴 (a == NULL인 상태)
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
			if (!(ft_isdigit(strs[i][j]) || strs[i][j] == '-'))	//	한글자씩 읽으며 숫자나 - 가 아닌경우 에러
				return ft_error();
			j++;
		}
		temp = ft_dc_lstnew(ft_atolli(strs[i]));	//	문자열을 숫자로 바꿔 새로운 노드 생성
		if (temp == NULL)	//	할당 실패시
		{
			ft_dc_lstclear(a);	//	노드를 모두 지우고
			return ft_error();	// 에러 출력
		}
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
	if (ft_strchr(argv[1], ' ') || ft_strchr(argv[1], '\t') || ft_strchr(argv[1], '\n')
		|| ft_strchr(argv[1], '\v') || ft_strchr(argv[1], '\f') || ft_strchr(argv[1], '\r')) // "1 2 3 4 5" 인 경우
	{
		// 첫번째 인자를 isspace기준으로 나눈다.
		strs = ft_split_isspace(argv[1]);
		make_a(a, strs, 0);
		ft_free_strs(strs);
	}
	else // "" 가 없는 경우
		make_a(a, argv, 1);
	if (*a == NULL)
		exit(-1);
	ft_printf("good\n");	//	test
	ft_dc_lst_print(*a);	//	test
}
```

<br>