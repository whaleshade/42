/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:03:59 by jibang            #+#    #+#             */
/*   Updated: 2022/06/09 21:29:17 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push(int *index, t_list **p_stack)
{
	t_list	*tmp;

	tmp = ft_lstnew(index);
	if (!tmp)
	{
		ft_printf("Error\n");
		exit(0);
	}
	ft_lstadd_front(p_stack, tmp);
}
