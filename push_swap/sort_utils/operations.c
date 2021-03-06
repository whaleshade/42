/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:03:20 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 22:12:06 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_swap(t_list **op_stk, t_list **lst, char *str)
{
	t_list	*tmp;
	int		size;

	size = 0;
	if (*lst == NULL)
		return ;
	size = ft_lstsize(*lst);
	if (size == 0)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	tmp->next = *lst;
	*lst = tmp;
	ft_stack_ops(op_stk, "s", str);
}

void	do_rotat(t_list **op_stk, t_list **lst, char *str)
{
	t_list	*tmp;
	t_list	*last;
	int		size;

	size = 0;
	if (*lst == NULL)
		return ;
	size = ft_lstsize(*lst);
	if (size == 0)
		return ;
	tmp = (*lst)->next;
	last = ft_lstlast(*lst);
	(*lst)->next = NULL;
	last->next = (*lst);
	(*lst) = tmp;
	ft_stack_ops(op_stk, "r", str);
}

t_list	*ft_newlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst -> next == NULL)
		return (lst);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	do_rvrot(t_list **op_stk, t_list **lst, char *str)
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
	ft_stack_ops(op_stk, "rr", str);
}

void	do_push(t_list **op_stk, t_list **lst1, t_list **lst2, char *str)
{
	t_list	*tmp;

	if (*lst1 == NULL)
		return ;
	tmp = (*lst1);
	*lst1 = (*lst1)->next;
	tmp->next = NULL;
	if (*lst2 == NULL)
	{
		*lst2 = tmp;
	}
	else
		ft_lstadd_front(lst2, tmp);
	ft_stack_ops(op_stk, "p", str);
}
