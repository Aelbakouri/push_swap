/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:52:15 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/29 22:24:39 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/* exit_error:
*   Writes "Error\n" to the standard output after freeing stack a and b.
*	Exits with standard error code 1.
*/
void	exit_error(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}

/* nb_abs:
*	Returns the absolute value of a given number.
*	The absolute value of a number is used to measure the distance of that
*	number from 0, whether it is positive or negative (abs value of -6 is 6).
*/
int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

static char	**fill_tab(char **av, int *size)
{
	int		i;
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

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}