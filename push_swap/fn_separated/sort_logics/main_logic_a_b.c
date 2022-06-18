/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_logic_a_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:21:51 by jibang            #+#    #+#             */
/*   Updated: 2022/06/18 22:24:10 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	logic_on_a(t_stack *stk, int k, int min)
{
	t_pos pos;
	t_cnt cnt;

	if ((stk)->a == NULL || k == 0)
		return;
	if (ft_is_sorted_chunk((stk)->a, k))
		return;
	if (k == 1 || k == 2 || k == 3)
	{
		case_by_case_a(stk, k);
		return ;
	}
	else
	{
		ft_set_cnt_zero(&cnt);
		pos.pv1 = 0;
		pos.pv2 = 0;
		pos.pv1 = (k / 3) + min + 1;
		pos.pv2 = 2 * (k / 3) + min + 1;
		chunk_div_a(stk, pos, &cnt, k);
	}
	chunk_rrr_a(stk, &cnt);
	logic_on_a(stk, cnt.ra, pos.pv2);
	logic_on_b(stk, cnt.rb, pos.pv1);
	logic_on_b(stk, cnt.pb - cnt.rb, pos.pv1 - (k / 3));
}

void logic_on_b(t_stack *stk, int k, int min)
{
	int i;
	t_pos	pos;
	t_cnt	cnt;

	if ((stk)->b == NULL || k == 0)
		return;
	else if (ft_is_rev_sorted_chunk((stk)->b, k))
	{
		i = -1;
		while (++i < k)
			do_push(&(stk)->op, &(stk)->b, &(stk)->a, "a");
	}
	else if (k == 1 || k == 2 || k == 3)
		case_by_case_b(stk, k);
	else
	{
		ft_set_cnt_zero(&cnt);
		pos.pv1 = k / 3 + min - 1;
		pos.pv2 = 2 * (k / 3) + min - 1;
		chunk_div_b(stk, pos, &cnt, k);
		logic_on_a(stk, cnt.pa - cnt.ra, pos.pv2);
		chunk_rrr_b(stk, &cnt);
		logic_on_a(stk, cnt.ra, pos.pv1);
		logic_on_b(stk, cnt.rb, pos.pv1 - (k / 3));
	}
}
