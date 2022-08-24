
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