/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:26 by ael-bako          #+#    #+#             */
/*   Updated: 2023/01/05 14:37:43 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* rrotate:
*	Brings the bottom element of a stack to the top.
*/
void	rrotate(t_list **stack, char *str)
{
	t_list	*tmp;
	t_list	*bef_last;

	if (ft_stack_size(*stack) < 2)
		return ;
	tmp = ft_stack_bottom(*stack);
	bef_last = ft_stack_before_bottom(*stack);
	bef_last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (str)
		ft_putstr(str);
}

/* rrr:
*	Brings the bottom element of both stack a and stack be
*	to the top of their respective stacks.
*	Prints "rrr" to the standard output.
*/
void	rrr(t_list **stack_a, t_list **stack_b)
{
	rrotate(stack_a, 0);
	rrotate(stack_b, 0);
	ft_putstr("rrr");
}
