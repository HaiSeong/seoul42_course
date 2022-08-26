/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hajeong <hajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:10:20 by hajeong           #+#    #+#             */
/*   Updated: 2022/08/25 21:31:58 by hajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef long long int	t_dc_data;

typedef struct s_dc_list
{
	struct s_dc_list	*left;
	t_dc_data			data;
	struct s_dc_list	*right;
}	t_dc_list;

typedef struct s_cost_info
{
	size_t	cost_sum;
	int		best_way;
	size_t	ra_cost;
	size_t	rra_cost;
	size_t	rb_cost;
	size_t	rrb_cost;
}	t_cost_info;

t_dc_list	*ft_dc_lstnew(t_dc_data data);
void		ft_dc_lstadd_front(t_dc_list **lst, t_dc_list *new);
t_dc_data	ft_dc_lstdel_front(t_dc_list **lst);
size_t		ft_dc_lstsize(t_dc_list *lst);
void		ft_dc_lstclear(t_dc_list **lst);

void		ra(t_dc_list **lst);
void		rb(t_dc_list **lst);
void		ra_no_print(t_dc_list **lst);
void		rb_no_print(t_dc_list **lst);
void		rr(t_dc_list **lst_a, t_dc_list **list_b);

void		rra(t_dc_list **lst);
void		rrb(t_dc_list **lst);
void		rra_no_print(t_dc_list **lst);
void		rrb_no_print(t_dc_list **lst);
void		rrr(t_dc_list **lst_a, t_dc_list **list_b);

int			pa(t_dc_list **lst_a, t_dc_list **lst_b);
int			pb(t_dc_list **lst_a, t_dc_list **lst_b);

void		sa(t_dc_list *lst_a);
void		sb(t_dc_list *lst_b);
void		sa_no_print(t_dc_list *lst_a);
void		sb_no_print(t_dc_list *lst_b);
void		ss(t_dc_list *lst_a, t_dc_list *lst_b);

t_dc_list	*copy_a(t_dc_list **a);
void		bubble_sort(t_dc_list *copy);
t_dc_data	get_small_pivot(t_dc_list *copy);
t_dc_data	get_big_pivot(t_dc_list *copy);

void		sort2(t_dc_list **a);
void		sort3(t_dc_list **a);
void		move_all_b(t_dc_list **a, t_dc_list **b,
				t_dc_list **copy, size_t n);
void		organize_stack(t_dc_list **a);

size_t		get_ra_cost(t_dc_list **a, t_dc_data data);
void		set_cost_info_a(t_cost_info *cost_info,
				size_t ra_cost, t_dc_list *a);
void		set_cost_info_b(t_cost_info *cost_info,
				size_t rb_cost, t_dc_list *b);
void		cal_sum_cost1(t_cost_info *cost_info);
void		cal_sum_cost2(t_cost_info *cost_info);
t_cost_info	get_best_cost(t_dc_list **a, t_dc_list **b);

void		rotate_best_cost(t_dc_list **a, t_dc_list **b,
				t_cost_info *cost_info);
void		rotate1(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info);
void		rotate2(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info);
void		rotate3(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info);
void		rotate4(t_dc_list **a, t_dc_list **b, t_cost_info *cost_info);

#endif
