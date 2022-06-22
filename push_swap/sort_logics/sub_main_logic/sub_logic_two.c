/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_logic_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 13:32:34 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 22:09:53 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_sort_two_a(t_list **op_stk, t_list **lst1)
{
	int		t;
	int		b;

	if (ft_is_sorted_chunk(*lst1, 2))
		return ;
	t = *(int *)((*lst1)->content);
	b = *(int *)((*lst1)->next->content);
	if (t > b)
		do_swap(op_stk, lst1, "a");
	return ;
}

void	ft_sort_two_b(t_list **op_stk, t_list **lst1, t_list **lst2)
{
	int		t;
	int		b;

	t = *(int *)((*lst2)->content);
	b = *(int *)((*lst2)->next->content);
	if (t > b)
	{
		do_push(op_stk, lst2, lst1, "a");
		do_push(op_stk, lst2, lst1, "a");
	}
	else if (t < b)
	{
		do_swap(op_stk, lst2, "b");
		do_push(op_stk, lst2, lst1, "a");
		do_push(op_stk, lst2, lst1, "a");
	}
}

void	ft_set_cnt_zero(t_cnt *t)
{
	(*t).pa = 0;
	(*t).pb = 0;
	(*t).ra = 0;
	(*t).rb = 0;
	(*t).sa = 0;
	(*t).sb = 0;
	(*t).rra = 0;
	(*t).rrb = 0;
}
