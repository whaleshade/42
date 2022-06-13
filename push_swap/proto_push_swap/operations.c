/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:03:20 by jibang            #+#    #+#             */
/*   Updated: 2022/06/13 16:17:22 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa, sb
void	do_swap(t_list **lst)
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
	//명령어 저장해야함
}

//ra, rb
void	do_rotat(t_list **lst)
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
	//명령어 저장해야함
}

//rra, rrb
t_list  *ft_newlast(t_list *lst)
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

void	do_rvrot(t_list **lst)
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

//pa,pb :: from lst1 to lst2
void	do_push(t_list **lst1, t_list **lst2)
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
		return ;
	}
	ft_lstadd_front(lst2, tmp);
}
