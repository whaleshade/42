/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_sort_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 19:19:37 by jibang            #+#    #+#             */
/*   Updated: 2022/06/13 17:42:34 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "operations.c" //to be removed

void	logic_on_a(t_list **a, t_list **b, int k, int min);
void	logic_on_b(t_list **a, t_list **b, int k, int min);


void	ft_set_cnt_zero(t_cnt *t)
{
	(*t).pa = 0;
	(*t).pb = 0;
	(*t).ra = 0;
	(*t).rb = 0;
	(*t).sa = 0;
	(*t).sb = 0;
	(*t).rra = 0;
	(*t).rrb = 0;
}

void	sort_nothing()
{
	return ;
}

void	sort_only_two(t_list **lst)
{
	int		t;
	int		b;

	t = *(int *)((*lst)->content);
	b = *(int *)((*lst)->next->content);
	if (t > b)
		do_swap(lst);
	return ;
}

void	sort_only_three(t_list **lst) //for optimization
{
	int		t;
	int		m;
	int		b;

	t = *(int *)((*lst)->content);
	m = *(int *)((*lst)->next->content);
	b = *(int *)((*lst)->next->next->content);
	if (t > m && t > b && m > b)
	{
		do_swap(lst);
		do_rvrot(lst);
	}
	else if (t > m && t > b && m < b)
		do_rotat(lst);
	else if (m > t && m > b && t < b)
	{
		do_swap(lst);
		do_rotat(lst);
	}
	else if (m > t && m > b && t > b)
		do_rvrot(lst);

	else if (b > t && b > m && t > m)
		do_swap(lst);
}



//###############################################################################
//########                                                            ###########
//########                                                            ###########
//########                                                            ###########
//########                                                            ###########
//for general case
void	ft_sort_two_a(t_list **lst1)
{
	int		t;
	int		b;

	t = *(int *)((*lst1)->content);
	b = *(int *)((*lst1)->next->content);
	if (t > b)
		do_swap(lst1);
	return ;
}

void	ft_sort_two_b(t_list **lst1, t_list **lst2)
{
	int		t;
	int		b;

	t = *(int *)((*lst2)->content);
	b = *(int *)((*lst2)->next->content);
	if (t > b)
	{
		do_push(lst2, lst1);
		do_push(lst2, lst1);
	}
	else if (t < b)
	{
		do_swap(lst2);
		do_push(lst2, lst1);
		do_push(lst2, lst1);
	}
}

void	ft_sort_three_a(t_list **lst1, t_list **lst2) //for optimization
{
	int		t;
	int		m;
	int		b;

	t = *(int *)((*lst1)->content);
	m = *(int *)((*lst1)->next->content);
	b = *(int *)((*lst1)->next->next->content);
	if (t > m && t > b && m > b)
	{
		do_rotat(lst1);
		do_push(lst1, lst2);
		do_push(lst1, lst2);
		do_swap(lst2);
		do_rvrot(lst1);
		do_push(lst2, lst1);
		do_push(lst2, lst1);
	}
	else if (t > m && t > b && m < b)
	{
		do_swap(lst1);
		do_rotat(lst1);
		do_swap(lst1);
		do_rvrot(lst1);
	}
	else if (m > t && m > b && t < b)
	{
		do_rotat(lst1);
		do_swap(lst1);
		do_rvrot(lst1);
	}
	else if (m > t && m > b && t > b)
	{
		do_push(lst1, lst2);
		do_swap(lst1);
		do_rotat(lst1);
		do_push(lst2, lst1);
		do_rvrot(lst1);
	}
	else if (b > t && b > m && t > m)
		do_swap(lst1);
}

void	ft_sort_three_b(t_list **lst1, t_list **lst2) //for optimization
{
	int		t;
	int		m;
	int		b;

	t = *(int *)((*lst2)->content);
	m = *(int *)((*lst2)->next->content);
	b = *(int *)((*lst2)->next->next->content);
	if (t > m && t > b && m > b)
	{
		do_push(lst2, lst1);
		do_push(lst2, lst1);
		do_push(lst2, lst1);
	}
	else if (t > m && t > b && m < b)
	{
		do_push(lst2, lst1);
		do_swap(lst2);
		do_push(lst2, lst1);
		do_push(lst2, lst1);
	}
	else if (m > t && m > b && t < b)
	{
		do_swap(lst2);
		do_push(lst2, lst1);
		do_swap(lst2);
		do_push(lst2, lst1);
		do_push(lst2, lst1);
	}
	else if (m > t && m > b && t > b)
	{
		do_swap(lst2);
		do_push(lst2, lst1);
		do_push(lst2, lst1);
		do_push(lst2, lst1);
	}
	else if (b > t && b > m && t > m)
	{
		do_swap(lst2);
		do_rotat(lst2);
		do_swap(lst2);
		do_push(lst2, lst1);
		do_push(lst2, lst1);
		do_rvrot(lst2);
		do_push(lst2, lst1);
	}
	else if (b > t && b > m && t < m)
	{
		do_push(lst2, lst1);
		do_rotat(lst1);
		do_swap(lst2);
		do_push(lst2, lst1);
		do_push(lst2, lst1);
		do_rvrot(lst1);
	}
}


///////////////////////////////////////////////////////////
////////               fixing...                ///////////
///////////////////////////////////////////////////////////

void	logic_on_a(t_list **a, t_list **b, int k, int min)
{
	int		i;
	int		pv1;
	int		pv2;
	int		top;
	t_cnt	cnt = {0, };

	if (*a == NULL || k == 0)
		return ;
	if (k == 1)
		return ;
	else if (k == 2)
	{
		ft_sort_two_a(a);
		return ;
	}
	else if (k == 3)
	{
		ft_sort_three_a(a, b);
		return ;
	}

	ft_printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
	ft_printf("\n/\\/\\/\\/\\in stack a......../\\/\\/\\/\\/\\\n");
	ft_printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
	ft_printf("\n-------------------------\n");
	ft_printf("k = %d", k);
	ft_printf("\n-------------------------\n");

	//logic
	//ft_sort_a();
	ft_set_cnt_zero(&cnt);
	//select 2 pivots, 1/3, 2/3
	pv1 = 0;
	pv2 = 0;
	pv1 = (k / 3) + min;
	pv2 = 2 * (k / 3) + min;
	ft_printf("\n=======on a=======\n");
	ft_printf("pv1 : %d  pv2 : %d", pv1, pv2);
	ft_printf("\n=======on a=======\n");
	ft_printf("\n----ops-----------\n");
	i = 0;
	while (i < k)
	{
		top = *(int *)((*a)->content);
		if (top >= pv2 && ft_lstsize(*a) != 1)
		{
			do_rotat(a); //ra
			(cnt.ra)++;
		ft_printf("\n-----------\n");
		ft_printf("top(curr) : %d", top);
		ft_printf("\n-----------\n");
		}
		else if (top < pv2)
		{
			do_push(a, b); //pb
			(cnt.pb)++;
			//여기서 아직 푸시가 안 된 상태일 때, 즉 처음일 때 rb 안 시켜야함
			if (top >= pv1 && ft_lstsize(*b) != 1)
			{
				do_rotat(b);
				(cnt.rb)++;
				ft_printf("rb :::: %d", cnt.rb);
		ft_printf("\n-----------\n");
		ft_printf("top(curr) : %d", top);
		ft_printf("\n-----------\n");
			}
			else if (top >= pv1)
				(cnt.rb)++;
		}
		i++;

////////////to be deleted---below////////////////////
	ft_printf("\n\n-----------------\n");
	t_list	*tmp1;
	tmp1 = *a;
	t_list	*tmp2;
	tmp2 = *b;

	ft_printf("\n ========A=======\n");
	while(tmp1)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp1->content);
		tmp1 = tmp1->next;
	}
	ft_printf("\n ========B=======\n");
	while(tmp2)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp2->content);
		tmp2 = tmp2->next;
	}
	ft_printf("\n-----------------\n\n");
////////////to be deleted-----upper//////////////////
	}
	//rra, rrb
	ft_printf("\n=======on a=======\n");
	ft_printf("ra : %d  rb : %d  pb : %d", cnt.ra, cnt.rb, cnt.pb);
	ft_printf("\n=================\n");

	if (cnt.ra >= cnt.rb)
	{
		i = 0;
		while (i < cnt.rb)
		{
			do_rvrot(b); //rrb;
			do_rvrot(a); //rra;
			(cnt.rra)++;
			(cnt.rrb)++;
			i++;
		}
		i = 0;
		while (i < cnt.ra - cnt.rb)
		{
			do_rvrot(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < cnt.ra)
		{
			do_rvrot(a);
			do_rvrot(b);
			(cnt.rra)++;
			(cnt.rrb)++;
			i++;
		}
		i = 0;
		while (i < cnt.rb - cnt.ra)
		{
			do_rvrot(b);
			i++;
		}
	}
	////----------finishing rr----------///
	ft_printf("\n\n-------rr------\n");
	t_list	*tmp3;
	tmp3 = *a;
	t_list	*tmp4;
	tmp4 = *b;

	ft_printf("\n ========A=======\n");
	while(tmp3)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp3->content);
		tmp3 = tmp3->next;
	}
	ft_printf("\n ========B=======\n");
	while(tmp4)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp4->content);
		tmp4 = tmp4->next;
	}
	ft_printf("\n-----------------\n\n");
////--------to be deleted-----upper--------/////

	logic_on_a(a, b, cnt.ra, pv2);
	////////////to be deleted---below////////////////////
	ft_printf("======big chunk sort======\n");
	t_list	*tmp1;
	tmp1 = *a;
	t_list	*tmp2;
	tmp2 = *b;

	ft_printf("\n ========A=======\n");
	while(tmp1)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp1->content);
		tmp1 = tmp1->next;
	}
	ft_printf("\n ========B=======\n");
	while(tmp2)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp2->content);
		tmp2 = tmp2->next;
	}
////////////to be deleted-----upper//////////////////
	logic_on_b(a, b, cnt.rb, pv1);
	logic_on_b(a, b, cnt.pb - cnt.rb, pv1 - (k / 3));
	ft_printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
	ft_printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
}














void logic_on_b(t_list **a, t_list **b, int k, int min)
{
	int 	i;
	int 	pv1;
	int 	pv2;
	int		top;
	t_cnt 	cnt = {0, };

	if (*b == NULL || k == 0)
		return;
	else if (k == 1)
	{
		do_push(b, a);
		return;
	}
	else if (k == 2)
	{
		ft_sort_two_b(a, b);
		return;
	}
	else if (k == 3)
	{
		ft_sort_three_b(a, b);
		return;
	}
	ft_printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
	ft_printf("\n/\\/\\/\\/\\in stack b......../\\/\\/\\/\\/\\\n");
	ft_printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n");
	ft_printf("\n-------------------------\n");
	ft_printf("k = %d", k);
	ft_printf("\n-------------------------\n");
	//ft_sort_b();
	//logic
	ft_set_cnt_zero(&cnt);
	//select 2 pivots, 1/3, 2/3
	pv1 = 0;
	pv2 = 0;
	pv1 = k / 3 + min; /// 해당 들어간 수 중에서 최소에서 더해줘야 함
	pv2 = 2 * (k / 3) + min;
	i = 0;
	while (i < k)
	{
		top = *(int *)((*b)->content);
		ft_printf("\n-----on b------\n");
		ft_printf("top(curr) : %d", top);
		ft_printf("\n-----------\n");
		if (top < pv1 && ft_lstsize(*b) != 1)
		{
			do_rotat(b); //rb
			(cnt.rb)++;
		}
		else if (top < pv1)
			(cnt.rb)++;
		else if (top >= pv1)
		{
			do_push(b, a); //pa
			(cnt.pa)++;
			if (top < pv2 && ft_lstsize(*a) != 1)
			{
				do_rotat(a); //ra
				(cnt.ra)++;
			}
			else if (top < pv2)
				(cnt.ra)++;
		}
		i++;
		////////////to be deleted---below////////////////////
	ft_printf("\n\n-----------------\n");
	t_list	*tmp1;
	tmp1 = *a;
	t_list	*tmp2;
	tmp2 = *b;

	ft_printf("\n ========A=======\n");
	while(tmp1)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp1->content);
		tmp1 = tmp1->next;
	}
	ft_printf("\n ========B=======\n");
	while(tmp2)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp2->content);
		tmp2 = tmp2->next;
	}
	ft_printf("\n-----------------\n\n");
	}
	logic_on_a(a, b, cnt.pa - cnt.ra, pv2);
	//rra, rrb
	ft_printf("\n=======on b========\n");
	ft_printf("ra : %d  rb : %d", cnt.ra, cnt.rb);
	ft_printf("\n=================\n");
	if (cnt.ra >= cnt.rb)
	{
		i = 0;
		while (i < cnt.rb)
		{
			do_rvrot(b); //rrb;
			do_rvrot(a); //rra;
			(cnt.rra)++;
			(cnt.rrb)++;
			i++;
		}
		i = 0;
		while (i < cnt.ra - cnt.rb)
		{
			do_rvrot(a);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < cnt.ra)
		{
			do_rvrot(a);
			do_rvrot(b);
			(cnt.rra)++;
			(cnt.rrb)++;
			i++;
		}
		i = 0;
		while (i < cnt.rb - cnt.ra)
		{
			do_rvrot(b);
			i++;
		}
	}
		////----------finishing rr----------///
	ft_printf("\n\n-------rr------\n");
	t_list	*tmp3;
	tmp3 = *a;
	t_list	*tmp4;
	tmp4 = *b;

	ft_printf("\n ========A=======\n");
	while(tmp3)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp3->content);
		tmp3 = tmp3->next;
	}
	ft_printf("\n ========B=======\n");
	while(tmp4)
	{
		ft_printf("node contents(index) : %d\n", *(int *)tmp4->content);
		tmp4 = tmp4->next;
	}
	ft_printf("\n-----------------\n\n");
////--------to be deleted-----upper--------/////
	logic_on_a(a, b, cnt.ra, pv1);
	logic_on_b(a, b, cnt.rb, pv1 - (k / 3));
}
