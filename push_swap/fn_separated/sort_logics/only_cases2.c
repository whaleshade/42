/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_cases2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:21:53 by jibang            #+#    #+#             */
/*   Updated: 2022/06/18 19:33:21 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	put_out_big_and_small(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	int idx;
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (i < 5)
	{
		idx = *(int *)(*lst1)->content;
		if (idx == 0 || idx == 4)
		{
			do_push(op_stk, lst1, lst2, "b");
			cnt++;
		}
		else if (cnt != 2)
			do_rotat(op_stk, lst1, "a");
		i++;
	}
}

void sort_only_five(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	if (ft_is_sorted_chunk(*lst1, 5))
		return ;
	put_out_big_and_small(op_stk, lst1, lst2);
	sort_only_three(op_stk, lst1);
	if (*(int *)(*lst2)->content == 0)
	{
		do_push(op_stk, lst2, lst1, "a");
		do_push(op_stk, lst2, lst1, "a");
		do_rotat(op_stk, lst1, "a");
	}
	else
	{
		do_push(op_stk, lst2, lst1, "a");
		do_rotat(op_stk, lst1, "a");
		do_push(op_stk, lst2, lst1, "a");
	}
}
