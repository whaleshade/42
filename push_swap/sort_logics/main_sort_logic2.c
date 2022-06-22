/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_logic2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 21:35:07 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 22:05:29 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void static	for_reduce_line_b(t_stack *stk, t_cnt *cnt)
{
	do_rotat(&(stk)->op, &(stk)->a, "a");
	(cnt->ra)++;
}

void	chunk_div_b(t_stack *stk, t_pos pos, t_cnt *cnt, int k)
{
	int		i;

	i = -1;
	while (++i < k)
	{
		pos.t = *(int *)(((stk)->b)->content);
		if (pos.t < pos.pv1 && ft_lstsize((stk)->b) != 1)
		{
			do_rotat(&(stk)->op, &(stk)->b, "b");
			(cnt->rb)++;
		}
		else if (pos.t < pos.pv1)
			(cnt->rb)++;
		else if (pos.t >= pos.pv1)
		{
			do_push(&(stk)->op, &(stk)->b, &(stk)->a, "a");
			(cnt->pa)++;
			if (pos.t < pos.pv2 && ft_lstsize((stk)->a) != 1)
				for_reduce_line_b(stk, cnt);
			else if (pos.t < pos.pv2)
				(cnt->ra)++;
		}
	}
}

void	rrr_else_b(t_stack *stk, t_cnt *cnt)
{
	int		i;

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

void	chunk_rrr_b(t_stack *stk, t_cnt *cnt)
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
		rrr_else_b(stk, cnt);
}

void	case_by_case_b(t_stack *stk, int k)
{
	if (k == 1)
	{
		do_push(&(stk)->op, &(stk)->b, &(stk)->a, "a");
		return ;
	}
	else if (k == 2)
	{
		ft_sort_two_b(&(stk)->op, &(stk)->a, &(stk)->b);
		return ;
	}
	else if (k == 3)
	{
		ft_sort_three_b(&(stk)->op, &(stk)->a, &(stk)->b);
		return ;
	}
}
