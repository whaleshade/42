/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:52:17 by jibang            #+#    #+#             */
/*   Updated: 2022/06/14 19:30:51 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "parsing.c" //to be removed
# include "index_sort.c" //to be removed
# include "stack_push.c" //to be removed
# include "sort_logic.c"

# define SIZE 1000 //the number we can input upto

int	ft_find_index(int n, int *indexed, int k)
{
	int		i;

	i = 0;
	while (i < k)
	{
		if (n == indexed[i])
			return (i);
		i++;
	}
	return (-1);
}

int	main(int ac, char *av[])
{
	int		i;
	int		j;
	int		k;
	char	**p;
	//int *parsed = (int *) malloc(sizeof(int) * ac); is declared, and to be free(parsed);
	int 	parsed[SIZE] = {0, };
	int		indexed[SIZE] = {0, };
	int		stacked[SIZE] = {0, };
	t_list	*stack_a = NULL;
	t_list	*stack_b = NULL;
	t_list 	*op_stk = NULL;

	if (ac == 1)
		return (0);
	if (ft_syntax_error(ac, av))
		return (0);
	//syntax is Ok..but check double number
	//before that, parsing is needed using ft_split
	i = 1;
	k = 0;
	while (i < ac)
	{
		if (ft_is_white_space(av[i]) || ft_is_nul(av[i]))
			return (0);
		//white space and null check...
		p = ft_split(av[i], ' ');
		j = 0;
		while (p[j] != NULL)
		{
			//check overflow
			if (ft_overflow_check(p[j]))
				return (0);
			//number indexing
			parsed[k] = ft_atoi(p[j]);
			//check num duplicates
			if (ft_check_duplicates(parsed, k))
				return (0);
			k++;
			j++;
		}
		//save nums to stack A
		i++;
	}

	i = 0;
	while (i < k)
	{
		ft_printf("%d\n", parsed[i]);
		i++;
	}
	ft_printf("=============\n");
	//indexing
	ft_memcpy(indexed, parsed, k * sizeof(int)); //ft_memcpy copies 1byte at a time
	ft_quick_sort(indexed, 0, k - 1);
	i = 0;
	while (i < k)
	{
		ft_printf("%d\n", indexed[i]);
		i++;
	}
	ft_printf("=============\n");
	i = 0;
	while (i < k)
	{
		stacked[i] = ft_find_index(parsed[i], indexed, k);
		//put idx into stack A
		ft_stack_push(&stacked[i], &stack_a);
		ft_printf("index : %d\n", stacked[i]);
		i++;
	}

	ft_printf("=============\n");

	//number of stacked nodes
	ft_printf("stacked size  : %d \n", ft_lstsize(stack_a));

	//before operations
	ft_printf("======before ops======\n");
	t_list	*tmp;
	tmp = stack_a;
	while(tmp)
	{
		ft_printf("node contents(index) : %d\n", *(int *)(tmp->content));
		tmp = tmp->next;
	}
	//////
	tmp = stack_a;
	ft_printf("\n top : %d", *(int *)(tmp->content));

	ft_printf("\n==================================\n");
	ft_printf("\n...................................\n");
	ft_printf("\n...................................\n");
	ft_printf("\n...................................\n");
	ft_printf("\n...................................\n");
////////////////////////////////////////////////////////////////////////////

	// //operations
	k = ft_lstsize(stack_a);
	if (k == 5)
	{
		sort_only_five(&op_stk, &stack_a, &stack_b);
	}
	else if (k == 4)
	{
		sort_only_four(&op_stk, &stack_a, &stack_b);
	}
	else if (k == 3)
	{
		//ft_sort_three_a(&stack_a, &stack_b);
		sort_only_three(&op_stk, &stack_a);
	}
	else if (k == 2)
	{
		//ft_sort_two_a(&stack_a);
		sort_only_two(&op_stk, &stack_a);
	}
	else if (k == 1 || k == 0)
		sort_nothing();
	else
		logic_on_a(&op_stk, &stack_a, &stack_b, k, 0);


//////////////////////////////////////////////////////////////////////////////////

	//after operations
ft_printf("======after ops======\n");
	t_list	*tmp1;
	tmp1 = stack_a;
	t_list	*tmp2;
	tmp2 = stack_b;

	ft_printf("\n ========A=======\n");
	while(tmp1)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp1->content);
		tmp1 = tmp1->next;
	}
	ft_printf("\n------------------------\n");
	ft_printf("\n ========B=======\n");
	while(tmp2)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp2->content);
		tmp2 = tmp2->next;
	}

	ft_printf("===========\n");

	//////////////////////////////////////////////////////////////////////
	ft_printf("\n\n\n===============final stacking==============\n");
	t_list	*opstk = NULL;
	char	*s = NULL;

	i = 0;
	opstk = op_stk;
	while (opstk)
	{
		s = (char *)(opstk->content);
		ft_printf("stack[%d] : %s\n", i, s);
		opstk = opstk->next;
		i++;
	}
	ft_printf("\n\n\n===============final stacking==============\n");


	return (0);
}
