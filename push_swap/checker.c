/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:04:24 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 21:54:33 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_ops_other_case(t_list **a, t_list **b, char *op)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		do_push(NULL, b, a, "a");
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		do_push(NULL, a, b, "b");
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		do_rvrot(NULL, a, "a");
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		do_rvrot(NULL, b, "b");
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		do_rrr(NULL, a, b, "ab");
	else
	{
		ft_printf("operation Error!\n");
		exit(0);
	}
}

void	do_ops_for_checker(t_list **a, t_list **b, char *op)
{
	if (ft_strncmp(op, "ra\n", 3) == 0)
		do_rotat(NULL, a, "a");
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		do_rotat(NULL, b, "b");
	else if (ft_strncmp(op, "rr", 3) == 0)
	{
		do_rotat(NULL, a, "a");
		do_rotat(NULL, b, "b");
	}
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		do_swap(NULL, a, "a");
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		do_swap(NULL, b, "b");
	else if (ft_strncmp(op, "ss\n", 3) == 0)
	{
		do_swap(NULL, a, "a");
		do_swap(NULL, b, "b");
	}
	else
		do_ops_other_case(a, b, op);
}

void	apply_logic(t_list **a, t_list **b)
{
	char	*op;
	t_list	*tmp;

	while (1)
	{
		tmp = *a;
		while (tmp)
		{
			ft_printf("%d\n", *((int *)tmp->content));
			tmp = tmp->next;
		}
		op = get_next_line(0);
		ft_printf("-------\n");
		if (op[0] == 'q')
			break ;
		do_ops_for_checker(a, b, op);
	}
	return ;
}

int	main(int ac, char **av)
{
	t_var	v;
	t_stack	stack;
	int		parsed[SIZE];
	int		indexed[SIZE];
	int		stacked[SIZE];

	if (ac == 1 || ft_syntax_error(ac, av))
		return (0);
	if (main_parse(ac, av, parsed, &(v.k)) == -1)
		return (0);
	ft_memcpy(indexed, parsed, v.k * sizeof(int));
	ft_quick_sort(indexed, 0, v.k - 1);
	v.i = -1;
	while (++(v.i) < v.k)
		stacked[v.i] = ft_find_index(parsed[v.i], indexed, v.k);
	v.i = -1;
	while (++(v.i) < v.k)
		ft_stack_push(&stacked[v.k - 1 - v.i], &stack.a);
	apply_logic(&stack.a, &stack.b);
	if (ft_is_sorted_chunk(stack.a, v.k))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&stack.a, &stack.op);
	return (0);
}
