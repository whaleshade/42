/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:52:17 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 21:57:35 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_ops(t_list *op)
{
	int		i;
	t_list	*tmp3;
	char	*s;

	i = 0;
	tmp3 = op;
	while (tmp3)
	{
		s = (char *)(tmp3->content);
		ft_printf("%s\n", s);
		tmp3 = tmp3->next;
		i++;
	}
}

int	main(int ac, char *av[])
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
	if (v.k <= 5)
		main_case_by_case(&stack.op, &stack.a, &stack.b, v.k);
	else
		logic_on_a(&stack, v.k, 0);
	put_ops(stack.op);
	free_all(&stack.a, &stack.op);
	return (0);
}
