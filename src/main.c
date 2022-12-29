/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:34 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/29 15:09:10 by ael-bako         ###   ########.fr       */
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
	push_and_save_three(&stack_a, &stack_b);
	push_swap(&stack_a, &stack_b, size);
	while (stack_a)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	// while (i < ac)
	// {
	// 	tmp = ft_lstnew(atoi(av[i]));
	// 	ft_lstadd_back(&a, tmp);
	// 	i++;
	// }
	// ft_lstadd_back(&b, ft_lstnew(atoi("10")));

	// while (a)
	// {
	// 	printf("%d\n", a->content);
	// 	a = a->next;
	// }
	system("leaks push_swap");
	(void)ac;
}
