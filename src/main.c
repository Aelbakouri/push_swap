/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:34 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/29 11:40:00 by ael-bako         ###   ########.fr       */
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

char	**fill_tab(char **av, int *size)
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
			printf("empty\n");
			return (0);
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
	push_and_save_three(&stack_a, &stack_b);
	// while (stack_b)
	// {
	// 	printf("%d\n", stack_b->content);
	// 	stack_b = stack_b->next;
	// }
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
