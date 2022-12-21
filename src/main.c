/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:34 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/21 15:46:49 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/push_swap.h"

void	sa(t_list *a)
{
	if (ft_lstsize(a) > 1)
	{
		int tmp;

		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
	}
}

void	sb(t_list *b)
{
	if (ft_lstsize(b) > 1)
	{
		int tmp;

		tmp = b->content;
		b->content = b->next->content;
		b->next->content = tmp;
	}
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
}

void	pa(t_list **a, t_list *b)
{
	if (b && *a)
		ft_lstadd_front(a, ft_lstnew(b->content));
}

void	pb(t_list *a, t_list **b)
{
	if (b && a)
		ft_lstadd_front(b, ft_lstnew(a->content));
}

void	ra(t_list *a)
{
	if (a)
	{
		ft_lstadd_back(&a, ft_lstnew(a->content));
		*a = *a->next;
	}
}

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
	int i = 1;
	t_list	*a;
	t_list	*b;
	t_list	*tmp;

	b = NULL;
	a = NULL;
	while (i < ac)
	{
		tmp = ft_lstnew(atoi(av[i]));
		ft_lstadd_back(&a, tmp);
		i++;
	}
	ft_lstadd_back(&b, ft_lstnew(atoi("10")));
	// pa(&a, b);
	// sa(a);
	// ra(a);

	// ra(a);
	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	(void)b;
	system("leaks push_swap");
}
