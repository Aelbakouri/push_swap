/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:34 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/29 18:45:40 by ael-bako         ###   ########.fr       */
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
		sa(stack_a);
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


static char	**fill_tab(char **av, int *size)
{
	int	i;
	char	*join;
	char	**tab;

	i = 1;
	join = NULL;
	while (av[i])
	{
		if (!is_empty(av[i]))
		{
			printf("empty param\n");
			exit(1);
		}
		join = ft_strjoin(join, av[i]);
		i++;
	}
	tab = ft_split(join, ' ', size);
	return (tab);
}

int main(int ac, char **av)
{

	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	char	**tab;

	tab = fill_tab(av, &size);
	if (!is_corr_inp(tab))
	{
		printf("Error\n");
		exit(1);
	}
	stack_a = fill_stack_content(size, tab);
	stack_b = NULL;
	size = ft_stack_size(stack_a);
	assign_index(stack_a, size + 1);
	ft_stack_before_bottom(stack_b);
	push_swap(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	system("leaks push_swap");
	(void)ac;
}
