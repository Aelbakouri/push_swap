/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:34 by ael-bako          #+#    #+#             */
/*   Updated: 2023/01/02 15:01:56 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_is_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2 && !stack_is_sorted(*stack_a))
		swap(stack_a, "sa");
	else if (stack_size == 3)
		sort_tree(stack_a);
	else if (stack_size > 3 && !stack_is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

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
			exit_error(NULL, NULL);
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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	**tab;

	tab = fill_tab(av, &size, ac);
	if (!is_corr_inp(tab))
		exit_error(NULL, NULL);
	stack_a = fill_stack_content(size, tab);
	stack_b = NULL;
	size = ft_stack_size(stack_a);
	assign_index(stack_a, size + 1);
	push_swap(&stack_a, &stack_b, size);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
}
