/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_logic_3_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:35:56 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 22:07:16 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	a_tmb_case(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	do_swap(op_stk, lst1, "a");
	do_push(op_stk, lst1, lst2, "b");
	do_swap(op_stk, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
	do_swap(op_stk, lst1, "a");
}

static void	a_tbm_case(t_list **op_stk, t_list **lst1)
{
	do_swap(op_stk, lst1, "a");
	do_rotat(op_stk, lst1, "a");
	do_swap(op_stk, lst1, "a");
	do_rvrot(op_stk, lst1, "a");
}

static void	a_mbt_case(t_list **op_stk, t_list **lst1)
{
	do_rotat(op_stk, lst1, "a");
	do_swap(op_stk, lst1, "a");
	do_rvrot(op_stk, lst1, "a");
}

static void	a_mtb_case(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	do_push(op_stk, lst1, lst2, "b");
	do_swap(op_stk, lst1, "a");
	do_rotat(op_stk, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
	do_rvrot(op_stk, lst1, "a");
}

void	ft_sort_three_a(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	t_pos	pos;

	if (ft_is_sorted_chunk(*lst1, 3))
		return ;
	pos.t = *(int *)((*lst1)->content);
	pos.m = *(int *)((*lst1)->next->content);
	pos.b = *(int *)((*lst1)->next->next->content);
	if (pos.t > pos.m && pos.t > pos.b && pos.m > pos.b)
		a_tmb_case(op_stk, lst1, lst2);
	else if (pos.t > pos.m && pos.t > pos.b && pos.m < pos.b)
		a_tbm_case(op_stk, lst1);
	else if (pos.m > pos.t && pos.m > pos.b && pos.t < pos.b)
		a_mbt_case(op_stk, lst1);
	else if (pos.m > pos.t && pos.m > pos.b && pos.t > pos.b)
		a_mtb_case(op_stk, lst1, lst2);
	else if (pos.b > pos.t && pos.b > pos.m && pos.t > pos.m)
		do_swap(op_stk, lst1, "a");
}
