/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:57:43 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 22:09:34 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_nothing(void)
{
	return ;
}

void	sort_only_two(t_list **op_stk, t_list **lst)
{
	t_pos	pos;

	pos.t = *(int *)((*lst)->content);
	pos.b = *(int *)((*lst)->next->content);
	if (pos.t > pos.b)
		do_swap(op_stk, lst, "a");
	return ;
}

void	sort_only_three(t_list **op_stk, t_list **lst)
{
	t_pos	pos;

	if (ft_is_sorted_chunk(*lst, 3))
		return ;
	pos.t = *(int *)((*lst)->content);
	pos.m = *(int *)((*lst)->next->content);
	pos.b = *(int *)((*lst)->next->next->content);
	if (pos.t > pos.m && pos.t > pos.b && pos.m > pos.b)
	{
		do_swap(op_stk, lst, "a");
		do_rvrot(op_stk, lst, "a");
	}
	else if (pos.t > pos.m && pos.t > pos.b && pos.m < pos.b)
		do_rotat(op_stk, lst, "a");
	else if (pos.m > pos.t && pos.m > pos.b && pos.t < pos.b)
	{
		do_swap(op_stk, lst, "a");
		do_rotat(op_stk, lst, "a");
	}
	else if (pos.m > pos.t && pos.m > pos.b && pos.t > pos.b)
		do_rvrot(op_stk, lst, "a");
	else if (pos.b > pos.t && pos.b > pos.m && pos.t > pos.m)
		do_swap(op_stk, lst, "a");
}

static void	four_case_pos_set(t_pos *pos, t_list *lst1)
{
	pos->t = *(int *)((lst1)->content);
	pos->m2 = *(int *)((lst1)->next->content);
	pos->m1 = *(int *)((lst1)->next->next->content);
	pos->b = *(int *)((lst1)->next->next->next->content);
}

void	sort_only_four(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	t_pos	pos;

	if (ft_is_sorted_chunk(*lst1, 4))
		return ;
	four_case_pos_set(&pos, *lst1);
	if (pos.b > pos.t && pos.b > pos.m2 && pos.b > pos.m1)
		ft_sort_three_a(op_stk, lst1, lst2);
	else if (pos.m1 > pos.t && pos.m1 > pos.m2 && pos.m1 > pos.b)
	{
		do_rvrot(op_stk, lst1, "a");
		ft_sort_three_a(op_stk, lst1, lst2);
	}
	else if (pos.m2 > pos.t && pos.m2 > pos.m1 && pos.m2 > pos.b)
	{
		do_swap(op_stk, lst1, "a");
		do_rotat(op_stk, lst1, "a");
		ft_sort_three_a(op_stk, lst1, lst2);
	}
	else if (pos.t > pos.m2 && pos.t > pos.m1 && pos.t > pos.b)
	{
		do_rotat(op_stk, lst1, "a");
		ft_sort_three_a(op_stk, lst1, lst2);
	}
}
