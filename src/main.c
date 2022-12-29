/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:34 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/28 14:28:16 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


// void	sa(t_list *a)
// {
// 	if (ft_lstsize(a) > 1)
// 	{
// 		int tmp;

// 		tmp = a->content;
// 		a->content = a->next->content;
// 		a->next->content = tmp;
// 	}
// }

// void	sb(t_list *b)
// {
// 	if (ft_lstsize(b) > 1)
// 	{
// 		int tmp;

// 		tmp = b->content;
// 		b->content = b->next->content;
// 		b->next->content = tmp;
// 	}
// }

// void	ss(t_list *a, t_list *b)
// {
// 	sa(a);
// 	sb(b);
// }

// void	ra(t_list *a)
// {
// 	if (a)
// 	{
// 		ft_lstadd_back(&a, ft_lstnew(a->content));
// 		*a = *a->next;
// 	}
// }

// void	rb(t_list **b)
// {
// 	t_list	*swaped;
// 	t_list	*tmp;

// 	swaped = *b;
// 	tmp = ft_lstnew(swaped->content);
// 	ft_lstadd_back(b, tmp);
// 	*swaped = *swaped->next;
// }

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
	// ft_stack_add_back(&stack_b, stack_new(65));
	// ft_stack_add_back(&stack_b, stack_new(16));
	push_and_save_three(&stack_a, &stack_b);
	// while (stack_a)
	// {
	// 	printf("%d\n", stack_a->index);
	// 	stack_a = stack_a->next;
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
	// system("leaks push_swap");
	(void)ac;
}
