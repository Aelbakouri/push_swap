/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:26 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/31 17:32:23 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrotate(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*bef_last;

	tmp = ft_stack_bottom(*stack);
	bef_last = ft_stack_before_bottom(*stack);
	bef_last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (str)
		ft_putstr(str);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a, 0);
	rrotate(stack_b, 0);
}

void	do_oper_b(t_list **a, t_list **b, char *line)
{
	if (!str_ncmp(line, "ra", 3))
		rotate(a, 0);
	else if (!str_ncmp(line, "rb", 3))
		rotate(b, 0);
	else if (!str_ncmp(line, "rr", 3))
		rr(a, b);
	else if (!str_ncmp(line, "rra", 4))
		rrotate(a, 0);
	else if (!str_ncmp(line, "rrb", 4))
		rrotate(b, 0);
	else
		rrr(a, b);
}

void	do_oper_a(t_list **a, t_list **b, char *line)
{
	if (!str_ncmp(line, "sa", 3))
		swap(a, 0);
	else if (!str_ncmp(line, "sb", 3))
		swap(b, 0);
	else if (!str_ncmp(line, "ss", 3))
		ss(a, b);
	else if (!str_ncmp(line, "pa", 4))
		push(b, a, 0);
	else
		push(a, b, 0);
}
