/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 12:52:12 by jibang            #+#    #+#             */
/*   Updated: 2022/06/18 12:55:15 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	do_rr(t_list **lst)
{
	t_list	*last;
	t_list	*newlast;
	int		size;

	size = 0;
	if (*lst == NULL)
		return ;
	size = ft_lstsize(*lst);
	if (size == 0)
		return ;
	last = ft_lstlast(*lst);
	newlast = ft_newlast(*lst);
	last->next = *lst;
	*lst = last;
	newlast->next = NULL;
}

void	do_rrr(t_list **op_stk, t_list **lst1, t_list **lst2, char *str)
{
	do_rr(lst1);
	do_rr(lst2);
	ft_stack_ops(op_stk, "rr", str);
}
