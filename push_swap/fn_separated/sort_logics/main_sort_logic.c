/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:19:37 by jibang            #+#    #+#             */
/*   Updated: 2022/06/18 22:31:27 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chunk_div_a(t_stack *stk, t_pos pos, t_cnt *cnt, int k)
{
	int i;

	i = 0;
	while (i < k)
	{
		pos.t = *(int *)(((stk)->a)->content);
		if (pos.t >= pos.pv2 && ft_lstsize((stk)->a) != 1)
		{
			do_rotat(&(stk)->op, &(stk)->a, "a");
			(cnt->ra)++;
		}
		else if (pos.t < pos.pv2)
		{
			do_push(&(stk)->op, &(stk)->a, &(stk)->b, "b");
			(cnt->pb)++;
			if (pos.t >= pos.pv1 && ft_lstsize((stk)->b) != 1)
			{
				do_rotat(&(stk)->op, &(stk)->b, "b");
				(cnt->rb)++;
			}
			else if (pos.t >= pos.pv1)
				(cnt->rb)++;
		}
		i++;
	}
}

void	rrr_else_a(t_stack *stk, t_cnt *cnt)
{
	int i;

	i = 0;
	while (i < cnt->ra)
	{
		do_rrr(&(stk)->op, &(stk)->a, &(stk)->b, "ab");
		(cnt->rra)++;
		(cnt->rrb)++;
		i++;
	}
	i = 0;
	while (i < cnt->rb - cnt->ra)
	{
		do_rvrot(&(stk)->op, &(stk)->b, "b");
		i++;
	}
}

void chunk_rrr_a(t_stack *stk, t_cnt *cnt)
{
	int		i;

	if (cnt->ra >= cnt->rb)
	{
		i = 0;
		while (i < cnt->rb)
		{
			do_rrr(&(stk)->op, &(stk)->a, &(stk)->b, "ab");
			(cnt->rra)++;
			(cnt->rrb)++;
			i++;
		}
		i = 0;
		while (i < cnt->ra - cnt->rb)
		{
			do_rvrot(&(stk)->op, &(stk)->a, "a");
			i++;
		}
	}
	else
		rrr_else_a(stk, cnt);
}

void	case_by_case_a(t_stack *stk, int k)
{
	if (k == 1)
		return;
	else if (k == 2)
	{
		ft_sort_two_a(&(stk)->op, &(stk)->a);
		return;
	}
	else if (k == 3)
	{
		ft_sort_three_a(&(stk)->op, &(stk)->a, &(stk)->b);
		return;
	}
}
