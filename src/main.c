/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:34 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/26 19:15:49 by ael-bako         ###   ########.fr       */
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

int main(int ac, char **av)
{

	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	*join;
	char	**tab;

	size = 0;
	while (av[++size])
		join = ft_strjoin(join, av[size]);
	tab = ft_split(join, ' ');
	if (!is_corr_inp(tab))
	{
		printf("Error\n");
		exit(1);
	}
	stack_a = fill_stack_content(ac, tab);
	stack_b = NULL;
	size = ft_stack_size(stack_a);
	assign_index(stack_a, size + 1);
	//ft_stack_add_back(&stack_b, stack_new(65));
	//ft_stack_add_back(&stack_b, stack_new(16));
	while (stack_a)
	{
		printf("%d\n", stack_a->index);
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
	// (void)b;
	// system("leaks push_swap");
}
