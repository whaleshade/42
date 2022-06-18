/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:42:05 by jibang            #+#    #+#             */
/*   Updated: 2022/06/18 19:43:26 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_white_space(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' \
			|| str[i] == '\b' || str[i] == '\v' \
			|| str[i] == '\n' || str[i] == '\r' \
			|| str[i] == '\f' || str[i] == '\a')
		{
			j++;
			if (j == (int)ft_strlen(str))
			{
				ft_printf("Error\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}

int	ft_is_nul(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
