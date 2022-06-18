/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_logic_3_b2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:44:31 by jibang            #+#    #+#             */
/*   Updated: 2022/06/18 22:31:30 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	b_btm_case(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	do_push(op_stk, lst2, lst1, "a");
	do_swap(op_stk, lst2, "b");
	do_push(op_stk, lst2, lst1, "a");
	do_swap(op_stk, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
}

void	b_bmt_case(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	do_push(op_stk, lst2, lst1, "a");
	do_rotat(op_stk, lst1, "a");
	do_swap(op_stk, lst2, "b");
	do_push(op_stk, lst2, lst1, "a");
	do_push(op_stk, lst2, lst1, "a");
	do_rvrot(op_stk, lst1, "a");
}
