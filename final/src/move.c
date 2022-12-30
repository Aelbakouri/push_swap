/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:19 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/29 14:29:38 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rev_rotate_both(t_list**a, t_list**b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

static void	rotate_both(t_list**a, t_list**b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

static void	rotate_a(t_list **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate(a, "ra");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrotate(a, "rra");
			(*cost)++;
		}
	}
}

static void	rotate_b(t_list **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rotate(b, "rb");
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrotate(b, "rrb");
			(*cost)++;
		}
	}
}

void	move(t_list **a, t_list **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	push(b, a, "pa");
}
