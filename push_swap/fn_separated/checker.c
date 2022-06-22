#include "push_swap.h"

#include "push_swap.h"
# include "./parse/parsing.c"
# include "./parse/parsing2.c"
# include "./sort_utils/index_sort.c"
# include "stack_push.c"
# include "./sort_logics/main_sort_logic.c"
# include "./sort_logics/main_sort_logic2.c"
# include "./sort_logics/main_logic_a_b.c"
# include "./sort_logics/sub_main_logic/sub_logic_two.c"
# include "./sort_logics/sub_main_logic/sub_logic_3_a.c"
# include "./sort_logics/sub_main_logic/sub_logic_3_b.c"
# include "./sort_logics/sub_main_logic/sub_logic_3_b2.c"
# include "./sort_logics/only_cases.c"
# include "./sort_logics/only_cases2.c"
# include "./sort_utils/check_sorted.c"
# include "./sort_utils/stack_ops.c"
# include "./sort_utils/operations.c"
# include "./sort_utils/operations2.c"

# define SIZE 1000 //the number we can input upto

void	main_case_by_case(t_list **op, t_list **a, t_list **b, int k)
{
	if (k == 5)
		sort_only_five(op, a, b);
	else if (k == 4)
		sort_only_four(op, a, b);
	else if (k == 3)
		sort_only_three(op, a);
	else if (k == 2)
		sort_only_two(op, a);
	else if (k == 1 || k == 0)
		sort_nothing();
}

int	main_parse(int ac, char **av, int *parsed, int *k)
{
	int		i;
	int		j;
	char	**p;

	i = 1;
	*k = 0;
	while (i < ac)
	{
		if (ft_is_white_space(av[i]) || ft_is_nul(av[i]))
			return (-1);
		p = ft_split(av[i], ' ');
		j = 0;
		while (p[j] != NULL)
		{
			if (ft_overflow_check(p[j]))
				return (-1);
			parsed[*k] = ft_atoi(p[j]);
			if (ft_check_duplicates(parsed, *k))
				return (-1);
			(*k)++;
			j++;
		}
		i++;
	}
	return (0);
}


int	ft_checker(t_list *lst, int k)
{
	int		i;
	int		x;
	int		idx;

	i = 0;
	x = *(int *)lst->content;
	while (i < k)
	{
		idx = *(int *)lst->content;
		if (x != idx)
		{
			ft_printf("KO\n");
			exit(0);
		}
		x++;
		lst = lst->next;
		i++;
	}
	ft_printf("OK\n");
	return (1);
}

void	put_ops(t_list *op, t_list *a)
{
	int		i;
	t_list	*tmp3 = NULL;
	char	*s = NULL;
	int		k;

	i = 0;
	tmp3 = a;
	k = ft_lstsize(tmp3);
	tmp3 = op;
	while (tmp3)
	{
		s = (char *)(tmp3->content);
		ft_printf("%s\n", s);
		tmp3 = tmp3->next;
		i++;
	}
	ft_checker(a, k);
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
	put_ops(stack.op, stack.a);
	return (0);
}

