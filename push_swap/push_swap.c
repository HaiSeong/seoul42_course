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

int	ft_error(void)
{
	write(2, "Error\n", 6);
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
	int			i;
	int			j;
	t_dc_list	*temp;

	i = 0;
	while (strs[i] != NULL)
		i++;
	while (i-- > end)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			if (!(ft_isdigit(strs[i][j])
				|| (strs[i][j] == '-' && ft_strlen(strs[i]) != 1)))
				return (-1);
			j++;
		}
		temp = ft_dc_lstnew(ft_atolli(strs[i]));
		if (temp == NULL)
			return (-1);
		ft_dc_lstadd_front(a, temp);
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
	if (ft_strchr(argv[1], ' ') || ft_strchr(argv[1], '\t')
		|| ft_strchr(argv[1], '\n') || ft_strchr(argv[1], '\v')
		|| ft_strchr(argv[1], '\f') || ft_strchr(argv[1], '\r'))
	{
		strs = ft_split_isspace(argv[1]);
		if (make_a(a, strs, 0) == -1 || argc != 2)
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

int	main(int argc, char *argv[])
{
	t_dc_list	*a;
	t_dc_list	*b;
	t_dc_list	*copy;
	t_cost_info	cost_info;

	argv_to_stack(&a, argc, argv);
	if (ft_dc_lstsize(a) >= 3)
	{
		copy = copy_a(&a);
		bubble_sort(copy);
		check_double(&a, &copy);
		move_all_b(&a, &b, &copy, ft_dc_lstsize(copy) / 3 * 2);
		sort3(&a);
		while (b != NULL)
		{
			cost_info = get_best_cost(&a, &b);
			rotate_best_cost(&a, &b, &cost_info);
			pa(&a, &b);
		}
		organize_stack(&a);
		ft_dc_lstclear(&copy);
	}
	else if (ft_dc_lstsize(a) == 2)
		sort2(&a);
	ft_dc_lstclear(&a);
}
