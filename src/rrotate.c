/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:39:31 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/29 15:40:43 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rrotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*bef_last;

	tmp = ft_stack_bottom(*stack);
	bef_last = ft_stack_before_bottom(*stack);
	bef_last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_list **stack_a)
{
	rrotate(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_list **stack_b)
{
	rrotate(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_putstr("rrr\n");
}
