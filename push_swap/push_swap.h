/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibang <jibang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:21:44 by jibang            #+#    #+#             */
/*   Updated: 2022/06/19 22:24:43 by jibang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SIZE 100000
# include "./libft/libft.h"

typedef struct s_cnt
{
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		sa;
	int		sb;
	int		rra;
	int		rrb;
}	t_cnt;

typedef struct s_pos
{
	int		t;
	int		m;
	int		m1;
	int		m2;
	int		b;
	int		pv1;
	int		pv2;
	int		min;
}	t_pos;

typedef struct s_stack
{
	t_list	*op;
	t_list	*a;
	t_list	*b;
}	t_stack;

typedef struct s_var
{
	int		min;
	int		i;
	int		j;
	int		k;
}	t_var;

typedef struct s_iter
{
	int		i;
	int		x;
	int		idx;
}	t_iter;

//sort check
int		ft_is_sorted_chunk(t_list *lst, int k);
int		ft_is_rev_sorted_chunk(t_list *lst, int k);

//stack_ops
void	ft_stack_ops(t_list **op_stk, char *op, char *stk);
void	ft_stack_push(int *index, t_list **p_stack);

//ops
void	do_swap(t_list **op_stk, t_list **lst, char *str);
void	do_rotat(t_list **op_stk, t_list **lst, char *str);
void	do_rvrot(t_list **op_stk, t_list **lst, char *str);
void	do_push(t_list **op_stk, t_list **lst1, t_list **lst2, char *str);
void	do_rrr(t_list **op_stk, t_list **lst1, t_list **lst2, char *str);

//only cases
void	sort_nothing(void);
void	sort_only_two(t_list **op_stk, t_list **lst);
void	sort_only_three(t_list **op_stk, t_list **lst);
void	sort_only_four(t_list **op_stk, t_list **lst1, t_list **lst2);
void	sort_only_five(t_list **op_stk, t_list **lst1, t_list **lst2);

//sub main_logic
void	ft_sort_two_a(t_list **op_stk, t_list **lst1);
void	ft_sort_two_b(t_list **op_stk, t_list **lst1, t_list **lst2);
void	ft_sort_three_a(t_list **op_stk, t_list **lst1, t_list **lst2);
void	ft_sort_three_b(t_list **op_stk, t_list **lst1, t_list **lst2);
void	ft_set_cnt_zero(t_cnt *t);

//main logic
void	logic_on_a(t_stack *stk, int k, int min);
void	logic_on_b(t_stack *stk, int k, int min);
int		main_parse(int ac, char **av, int *parsed, int *k);
void	main_case_by_case(t_list **op, t_list **a, t_list **b, int k);
void	put_ops(t_list *op);
void	case_by_case_a(t_stack *stk, int k);
void	chunk_rrr_a(t_stack *stk, t_cnt *cnt);
void	rrr_else_a(t_stack *stk, t_cnt *cnt);
void	chunk_div_a(t_stack *stk, t_pos pos, t_cnt *cnt, int k);
void	case_by_case_b(t_stack *stk, int k);
void	chunk_rrr_b(t_stack *stk, t_cnt *cnt);
void	rrr_else_b(t_stack *stk, t_cnt *cnt);
void	chunk_div_b(t_stack *stk, t_pos pos, t_cnt *cnt, int k);

//parse
int		ft_include_non_num(char *s);
int		ft_syntax_error(int ac, char **av);
int		ft_overflow_check(const char *str);
int		ft_check_duplicates(int *parsed, int k);
int		ft_is_white_space(char *str);
int		ft_is_nul(char *str);

//extra
void	b_btm_case(t_list **op_stk, t_list **lst1, t_list **lst2);
void	b_bmt_case(t_list **op_stk, t_list **lst1, t_list **lst2);
t_list	*ft_newlast(t_list *lst);

//index sort
void	ft_quick_sort(int *arr, int start, int end);
int		ft_find_index(int n, int *indexed, int k);
void	free_all(t_list **stk, t_list **op);
#endif
