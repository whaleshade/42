/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:58:19 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 21:54:56 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_list **stk, t_list **op)
{
	int		k;
	int		i;
	t_list	*tmp;

	k = ft_lstsize(*stk);
	i = 0;
	while (i < k)
	{
		tmp = *stk;
		*stk = (*stk)->next;
		free(tmp);
		i++;
	}
	ft_lstclear(op, free);
}
