/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:28 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/31 18:17:58 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	push(t_list **src, t_list **dest, char *str)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	if (str)
		ft_putstr(str);
}

void	swap(t_list **stack, char *str)
{
	int	tmp;

	if (ft_stack_size(*stack) > 1)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
		tmp = (*stack)->index;
		(*stack)->index = (*stack)->next->index;
		(*stack)->next->index = tmp;
	}
	if (str)
		ft_putstr(str);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
}

void	rotate(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_stack_bottom(*stack);
	tmp->next = NULL;
	last->next = tmp;
	if (str)
		ft_putstr(str);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
}
