/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:15:57 by jibang            #+#    #+#             */
/*   Updated: 2022/06/18 13:03:49 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	stacking(t_list **op_stk, char *opp)
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

static void	ops_case_for_a(t_list **op_stk, char *op)
{
	if (ft_strncmp(op, "s", 2) == 0)
		stacking(op_stk, "sa");
	else if (ft_strncmp(op, "p", 2) == 0)
		stacking(op_stk, "pa");
	else if (ft_strncmp(op, "rr", 3) == 0)
		stacking(op_stk, "rra");
	else if (ft_strncmp(op, "r", 2) == 0)
		stacking(op_stk, "ra");
}

static void	ops_case_for_b(t_list **op_stk, char *op)
{
	if (ft_strncmp(op, "s", 2) == 0)
		stacking(op_stk, "sb");
	else if (ft_strncmp(op, "p", 2) == 0)
		stacking(op_stk, "pb");
	else if (ft_strncmp(op, "rr", 3) == 0)
		stacking(op_stk, "rrb");
	else if (ft_strncmp(op, "r", 2) == 0)
		stacking(op_stk, "rb");
}

void	ft_stack_ops(t_list **op_stk, char *op, char *stk)
{
	if (ft_strncmp(stk, "a", 2) == 0)
		ops_case_for_a(op_stk, op);
	else if (ft_strncmp(stk, "b", 2) == 0)
		ops_case_for_b(op_stk, op);
	else if (ft_strncmp(stk, "ab", 3) == 0)
	{
		if (ft_strncmp(op, "rr", 3) == 0)
			stacking(op_stk, "rrr");
	}
}
