/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:28 by ael-bako          #+#    #+#             */
/*   Updated: 2023/01/05 14:42:03 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/
void	push(t_list **src, t_list **dest, char *str)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
	ft_putstr(str);
}

/*	swap:
*	Swap the first 2 elements at the top of given stack. such a or b
*	Do nothing if there is only one or no elements.
*	Prints "char *str" to the standard output.
*/
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

/* ss:
*	Swaps the top 2 elements of stack a and the top 2 elements
*	of stack b.
*	Prints "ss" to the standard output.
*/
void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	ft_putstr("ss");
}

/* rotate:
*	The top element of the stack is sent to the bottom.
*/
void	rotate(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_stack_size(*stack) < 2)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = ft_stack_bottom(*stack);
	tmp->next = NULL;
	last->next = tmp;
	if (str)
		ft_putstr(str);
}

/* rr:
*	Sends the top element of both stack a and stack b to the bottom
*	of their respective stacks.
*	Prints "rr" to the standard output.
*/
void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_putstr("rr");
}
