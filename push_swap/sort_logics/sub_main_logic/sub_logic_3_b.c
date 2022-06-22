/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_logic_3_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:36:02 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 22:07:32 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	b_tmb_case(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	do_push(op_stk, lst2, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
}

static void	b_tbm_case(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	do_push(op_stk, lst2, lst1, "a");
	do_swap(op_stk, lst2, "b");
	do_push(op_stk, lst2, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
}

static void	b_mbt_case(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	do_swap(op_stk, lst2, "b");
	do_push(op_stk, lst2, lst1, "a");
	do_swap(op_stk, lst2, "b");
	do_push(op_stk, lst2, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
}

static void	b_mtb_case(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	do_swap(op_stk, lst2, "b");
	do_push(op_stk, lst2, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
}

void	ft_sort_three_b(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	t_pos	pos;

	pos.t = *(int *)((*lst2)->content);
	pos.m = *(int *)((*lst2)->next->content);
	pos.b = *(int *)((*lst2)->next->next->content);
	if (pos.t > pos.m && pos.t > pos.b && pos.m > pos.b)
		b_tmb_case(op_stk, lst1, lst2);
	else if (pos.t > pos.m && pos.t > pos.b && pos.m < pos.b)
		b_tbm_case(op_stk, lst1, lst2);
	else if (pos.m > pos.t && pos.m > pos.b && pos.t < pos.b)
		b_mbt_case(op_stk, lst1, lst2);
	else if (pos.m > pos.t && pos.m > pos.b && pos.t > pos.b)
		b_mtb_case(op_stk, lst1, lst2);
	else if (pos.b > pos.t && pos.b > pos.m && pos.t > pos.m)
		b_btm_case(op_stk, lst1, lst2);
	else if (pos.b > pos.t && pos.b > pos.m && pos.t < pos.m)
		b_bmt_case(op_stk, lst1, lst2);
}
