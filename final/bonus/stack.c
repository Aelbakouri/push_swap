/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:52:56 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/31 18:18:10 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

t_list	*ft_stack_bottom(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_list	*ft_stack_before_bottom(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next && stack->next->next)
		stack = stack->next;
	return (stack);
}

t_list	*stack_new(int content)
{
	t_list	*lnew;

	lnew = malloc(sizeof(t_list));
	if (!lnew)
		return (NULL);
	lnew -> content = content;
	lnew->index = 0;
	lnew->cost_a = -1;
	lnew->cost_b = -1;
	lnew->pos = -1;
	lnew->target_pos = -1;
	lnew -> next = NULL;
	return (lnew);
}

void	ft_stack_add_back(t_list **stack, t_list *new)
{
	t_list	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = ft_stack_bottom(*stack);
	tail->next = new;
}

int	ft_stack_size(t_list	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
