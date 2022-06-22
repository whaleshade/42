/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:24:38 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 21:56:24 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	i = 0;
	*k = 0;
	while (++i < ac)
	{
		if (ft_is_white_space(av[i]) || ft_is_nul(av[i]))
			return (-1);
		p = ft_split(av[i], ' ');
		j = -1;
		while (p[++j] != NULL)
		{
			if (ft_overflow_check(p[j]))
				return (-1);
			parsed[*k] = ft_atoi(p[j]);
			if (ft_check_duplicates(parsed, *k))
				return (-1);
			free(p[j]);
			(*k)++;
		}
		free(p);
	}
	return (0);
}
