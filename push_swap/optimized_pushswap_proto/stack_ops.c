/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:15:57 by jibang            #+#    #+#             */
/*   Updated: 2022/06/13 22:55:42 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stacking(t_list **op_stk, char *opp)
{
	t_list	*tmp = NULL;
	char	*op = ft_strdup(opp);

	tmp = ft_lstnew(op);
	if (!tmp)
	{
		ft_printf("stack ops Error\n");
		exit(0);
	}
	ft_lstadd_back(op_stk, tmp);
}

void	ft_stack_ops(t_list **op_stk, char *op, char *stk)
{
	if (ft_strncmp(stk, "a", 1) == 0)
	{
		if (ft_strncmp(op, "s", 1) == 0)
			stacking(op_stk, "sa");
		if (ft_strncmp(op, "p", 1) == 0)
			stacking(op_stk, "pa");
		if (ft_strncmp(op, "r", 1) == 0)
			stacking(op_stk, "ra");
		if (ft_strncmp(op, "rr", 2) == 0)
			stacking(op_stk, "rra");
	}
	if (ft_strncmp(stk, "b", 1) == 0)
	{
		if (ft_strncmp(op, "s", 1) == 0)
			stacking(op_stk, "sb");
		if (ft_strncmp(op, "p", 1) == 0)
			stacking(op_stk, "pb");
		if (ft_strncmp(op, "r", 1) == 0)
			stacking(op_stk, "rb");
		if (ft_strncmp(op, "rr", 2) == 0)
			stacking(op_stk, "rrb");
	}
	if (ft_strncmp(stk, "r", 1) == 0)
	{
		if (ft_strncmp(op, "rr", 2) == 0)
			stacking(op_stk, "rrr");
	}
}
