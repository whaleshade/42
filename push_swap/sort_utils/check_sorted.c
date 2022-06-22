/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:43:21 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 22:10:32 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted_chunk(t_list *lst, int k)
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
			return (0);
		x++;
		lst = lst->next;
		i++;
	}
	return (1);
}

int	ft_is_rev_sorted_chunk(t_list *lst, int k)
{
	t_iter	iter;
	t_list	*tmp;

	iter.i = -1;
	tmp = lst;
	while (++(iter.i) < k)
	{
		iter.x = *(int *)tmp->content;
		tmp = tmp->next;
	}
	tmp = lst;
	iter.idx = *(int *)tmp->content;
	if (iter.idx != iter.x + k - 1)
		return (0);
	iter.x = iter.x + k - 1;
	iter.i = -1;
	while (++(iter.i) < k)
	{
		iter.idx = *(int *)tmp->content;
		if (iter.x != iter.idx)
			return (0);
		(iter.x)--;
		tmp = tmp->next;
	}
	return (1);
}
