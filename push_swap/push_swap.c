/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:30:07 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/24 14:15:45 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_dc_lst_print(t_dc_list *lst) //test
{
	t_dc_list	*now;

	now = lst;
	ft_printf("stack : ");
	if (lst == NULL)
		return ; 
	while (now->right != lst)
	{
		ft_printf("%d ", now->data);
		now = now->right;
	}
	
	ft_printf("%d\n", now->data);
}

int ft_error()
{
	ft_printf("Error\n");
	return (-1);
}

static void	ft_free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

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

int main(int argc, char *argv[])
{
	t_dc_list	*a;
	t_dc_list	*b;
	t_dc_list	*copy;

	argv_to_stack(&a, argc, argv);
	// 정렬 전 정보 구하기
	copy = copy_a(a);
	bubble_sort(copy);
	// 정렬 시작
}