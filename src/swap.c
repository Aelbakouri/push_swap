/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:26:43 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/23 14:30:47 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_list *stack)
{
	if (ft_lstsize(a) > 1)
	{
		int	tmp;
		tmp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = tmp;
		tmp = stack->index;
		stack->index = stack->next->index;
		stack->next->index = tmp;
	}
}

/* do_sa:
*	Swaps the top 2 elements of stack a.
*	Prints "sa" to the standard output.
*/
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* do_sb:
*	Swaps the top 2 elements of stack b.
*	Prints "sb" to the standard output.
*/
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* do_ss:
*	Swaps the top 2 elements of stack a and the top 2 elements
*	of stack b.
*	Prints "ss" to the standard output.
*/
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
