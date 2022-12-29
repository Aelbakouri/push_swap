/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:34:19 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/29 15:45:08 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*fill_stack_content(int ac, char **av)
{
	t_list		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			printf("invalid number");
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			ft_stack_add_back(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_list *stack_a, int size)
{
	t_list	*ptr;
	t_list	*highest;
	int		content;
		// int i = 0;

	while (--size > 0)
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
				highest->index = size;
	}
}
