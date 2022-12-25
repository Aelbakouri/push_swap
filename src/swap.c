/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:26:43 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/25 18:30:39 by ael-bako         ###   ########.fr       */
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

void	sa(t_list **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
