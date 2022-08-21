/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:30:07 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/21 22:04:32 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int ft_error()
{
	ft_printf("Error\n");
	return (-1);
}

int main(int argc, char *argv[])
{
	int			i;
	int			j;
	t_dc_list	*a;
	t_dc_list	*b;
	char		**strs;

	if (argc < 2)
		return ft_error();
	if (ft_strchr(argv[1], ' ') || ft_strchr(argv[1], '\t') || ft_strchr(argv[1], '\n')
		|| ft_strchr(argv[1], '\v') || ft_strchr(argv[1], '\f') || ft_strchr(argv[1], '\r')) // "1 2 3 4 5" 인 경우
	{
		// 첫번째 인자를 isspace기준으로 나눈다.
		strs = ft_split_isspace(argv[1]);
		for (i = 0; i<3; i++)
		{
			ft_printf("%d ", ft_atolli(strs[i]));
		}
		i = 0;
		while (strs[i] != NULL)
			i++;
		ft_printf("\n%d!!!\n ", i);
		while (i-- > 0)	//	반복문을 돌면서 하나씩 숫자로 만들어 배열에 추가 한다.
		{
			j = 0;
			while (strs[i][j] != '\0')
			{
				if (!(ft_isdigit(strs[i][j]) || strs[i][j] == '-'))
					return ft_error();
					j++;
			}
			b = ft_dc_lstnew(ft_atolli(strs[i]));	//	b를 잠시 temp노드로 사용
			if (b == NULL)
			{
				while (a != NULL)
					ft_dc_lstdel_front(&a);
				ft_error();
			}
			ft_dc_lstadd_front(&a, b);
		}
		// 나눠진 캐릭터 포인터 배열을 반복문으로 읽는다.
		// 읽은 문자열을 숫자로 바꿔 배열에 추가한다.
	}
	else // "" 가 없는 경우
	{
		a = NULL;
		i = argc;
		while (i-- > 1)	//	반복문을 돌면서 하나씩 숫자로 만들어 배열에 추가 한다.
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				if (!(ft_isdigit(argv[i][j]) || argv[i][j] == '-'))
					return ft_error();
				j++;
			}
			b = ft_dc_lstnew(ft_atolli(argv[i]));	//	b를 잠시 temp노드로 사용
			if (b == NULL)
			{
				while (a != NULL)
					ft_dc_lstdel_front(&a);
				ft_error();
			}
			ft_dc_lstadd_front(&a, b);
		}
	}
	ft_printf("good\n");
	// 스택에 하나씩 넣는다.
	// 정렬 시작	
}