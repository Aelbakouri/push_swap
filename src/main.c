/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:34 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/20 19:51:52 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../inc/push_swap.h"


// ra: rotate a — shift up all elements of stack a by 1. The first element becomes the last one.
void	ra()
{


}

void	sa(t_list *a)
{
	int tmp;

	tmp = a->content;
	a->content = a->next->content;
	a->next->content = tmp;
}

void	sb(t_list *b)
{
	int tmp;

	tmp = b->content;
	b->content = b->next->content;
	b->next->content = tmp;
}

void	ss(t_list *a, t_list *b)
{
	sa(a);
	sb(b);
}

void	pa(t_list *a, t_list *b)
{
	ft_lstadd_front(&a, b);
}

void	pb(t_list *a, t_list *b)
{
	ft_lstadd_back(&b, ft_lstlast(a));
}

int main(int ac, char **av)
{
	int i = 1;
	t_list	*a;
	t_list	*b;
	b = NULL;


	// a = ft_lstnew(atoi(av[i++]));
	a = NULL;

	while (i < ac)
	{
		ft_lstadd_back(&a, ft_lstnew(atoi(av[i])));
		i++;
	}
	// ft_lstadd_back(&b, ft_lstnew(atoi("10")));
	// pa(a, b);
	if (ft_lstsize(a) > 1)
		sa(a);

	while (a)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	// pa(a, b);
	(void)b;
}
