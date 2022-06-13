/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:59:57 by jibang            #+#    #+#             */
/*   Updated: 2022/06/06 19:05:34 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void ft_quick_sort(int *arr, int start, int end)
{
	int		pivot;
	int		i;
	int		j;

	if (start>=end)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while(j > start && arr[j] >= arr[pivot])
			j--;
		if (i >= j)
			break ;
		ft_swap(&arr[i], &arr[j]);
	}
	ft_swap(&arr[j], &arr[pivot]);
	ft_quick_sort(arr, start, j - 1);
	ft_quick_sort(arr, j + 1, end);
}
