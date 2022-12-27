/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:29 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/27 15:01:18 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	arg_is_nb(char *arg)
{
	int	i;

	i = 0;
	if (is_sign(arg[i]) && arg[i + 1] != '\0')
		i++;
	while (arg[i] && is_digit(arg[i]))
		i++;
	if (arg[i] && !is_digit(arg[i]))
		return (0);
	return (1);
}

static int	is_zero(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i])
		return (0);
	return (1);
}

int is_empty(char *av)
{
	int	i;

	i = 0;
	if (!av[i])
		return (0);
	while (av[i])
	{
		if (av[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	is_duplicates(char **av)
{

	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = 0;
		while (av[++j])
			if (j != i && !nb_cmp(av[i], av[j]))
				return (1);
	}
	return (0);
}

/* is_correct_input:
*   Checks if the given arguments are all numbers, without duplicates.
*   Return: 1 if the arguments are valid, 0 if not.
*/

int	is_corr_inp(char **av)
{
	int	i;
	int	nb_zero;

	i = 0;
	nb_zero = 0;
	if (is_duplicates(av))
		return (0);
	while (av[++i])
	{
		if (!arg_is_nb(av[i]) || !is_empty(av[i]))
			return (0);
		nb_zero += is_zero(av[i]);
	}
	if (nb_zero > 1)
		return (0);
	return (1);
}

// int main(int ac, char **av)
// {
// 	(void)ac;

// 	printf ("%d\n", is_empty(av[1]));
// }
