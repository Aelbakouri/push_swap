/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:19 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/26 19:14:10 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*fill_stack_content(int ac, char **av)
{
	int		i;
	t_list	*stack;
	long	nb;

	i = 0;
	stack = NULL;
	stack = NULL;
	while (ac >= i)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			printf("invalid number");
			return NULL;
		}
		if (i == 0)
			stack = stack_new((int)nb);
		else
			ft_stack_add_back(&stack, stack_new((int )nb));
		i++;
	}
	return (stack);
}

void	assign_index(t_list *stack_a, int stack_size)
{
	t_list	*ptr;
	t_list	*highest;
	int		content;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		content = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->content == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->content > content && ptr->index == 0)
			{
				content = ptr->content;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
