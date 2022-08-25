/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:30:07 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/25 21:18:10 by hajeong          ###   ########.fr       */
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
		if (make_a(a, strs, 0) == -1)
		{
			ft_dc_lstclear(a);	//	노드를 모두 지우고
			ft_error();	// 에러 출력
			exit(1);
		}
		ft_free_strs(strs);
	}
	else // "" 가 없는 경우
		make_a(a, argv, 1);
	if (*a == NULL)
		exit(1);
}

int main(int argc, char *argv[])
{
	t_dc_list	*a;
	t_dc_list	*b;
	t_dc_list	*copy;
	t_cost_info	cost_info;

	argv_to_stack(&a, argc, argv);
	// 정렬 전 정보 구하기
	copy = copy_a(a);
	bubble_sort(copy);
	// 정렬 시작
	if (ft_dc_lstsize(a) > 3)
	{
		move_all_b(&a, &b, &copy, ft_dc_lstsize(copy) / 3 * 2);
		sort3(&a);
		// ft_dc_lst_print(a);
		// ft_dc_lst_print(b);
		// cost_info = get_best_cost(&a, &b);
		// ft_printf("cost : %d\n", cost_info.cost_sum);
		// ft_printf("ra : %d\nrb : %d\nrra : %d\nrrb : %d\n best way : %d\n", cost_info.ra_cost, cost_info.rb_cost, cost_info.rra_cost, cost_info.rrb_cost, cost_info.best_way);
		// ra(&a);
		// pa(&a,&b);
		// ft_dc_lst_print(a);
		// ft_dc_lst_print(b);
		// cost_info = get_best_cost(&a, &b);
		// ft_printf("cost : %d\n", cost_info.cost_sum);
		// ft_printf("ra : %d\nrb : %d\nrra : %d\nrrb : %d\n best way : %d\n", cost_info.ra_cost, cost_info.rb_cost, cost_info.rra_cost, cost_info.rrb_cost, cost_info.best_way);
		// rra(&a);
		// pa(&a,&b);
		// ft_dc_lst_print(a);
		// ft_dc_lst_print(b);
		// cost_info = get_best_cost(&a, &b);
		// ft_printf("cost : %d\n", cost_info.cost_sum);
		// ft_printf("ra : %d\nrb : %d\nrra : %d\nrrb : %d\n best way : %d\n", cost_info.ra_cost, cost_info.rb_cost, cost_info.rra_cost, cost_info.rrb_cost, cost_info.best_way);
		
		// ra(&a);pa(&a,&b);
		// pa(&a,&b);
		// ra(&a);pa(&a,&b);
		// ra(&b);pa(&a,&b);
		// rra(&a);pa(&a,&b);
		// rr(&a,&b);rr(&a,&b);rb(&b);pa(&a,&b);
		// rr(&a,&b);rb(&b);pa(&a,&b);
		// rra(&a);pa(&a,&b);pa(&a,&b);
		// cost_info = get_best_cost(&a, &b);

		// ft_printf("cost : %d\n", cost_info.cost_sum);
		// ft_printf("ra : %d\nrb : %d\nrra : %d\nrrb : %d\n best way : %d\n", cost_info.ra_cost, cost_info.rb_cost, cost_info.rra_cost, cost_info.rrb_cost, cost_info.best_way);
		

		// exit(0); // for test
		while (b != NULL)
		{
			cost_info = get_best_cost(&a, &b);
			// ft_printf("0");
			rotate_best_cost(&a, &b, &cost_info);
			// ft_printf("1");
			pa(&a, &b);
			// if (ft_dc_lstsize(b) == 1)
			// 	break; 
			// ft_dc_lst_print(a);
			// ft_dc_lst_print(b);
		}

		// exit(0);
		organize_stack(&a);
		// ft_dc_lst_print(a);
		// ft_dc_lst_print(b);
	}
	else if (ft_dc_lstsize(a) == 3)
		sort3(&a);
	else if (ft_dc_lstsize(a) == 2)
		sort2(&a);
	ft_dc_lstclear(&copy);
	ft_dc_lstclear(&a);
}
