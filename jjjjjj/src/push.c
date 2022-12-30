/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:47 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/30 17:00:29 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* push:
*	Pushes the top element of src stack to the top of dest stack.
*/
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

/* do_pa:
*	Pushes the top element of stack b to the top of stack a.
*	Prints "pa" to the standard output.
*/
void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

/* do_pb:
*	Pushes the top element of stack a to the top of stack b.
*	Prints "pb" to the standard output.
*/
void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
