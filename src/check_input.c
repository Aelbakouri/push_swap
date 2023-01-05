/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:00:29 by ael-bako          #+#    #+#             */
/*   Updated: 2023/01/05 14:43:29 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* arg_is_nb:
*   Checks if the argument is a number. +1 1 and -1 are all valid numbers.
*   Return: 1 if the argument is a number, 0 if not.
*/
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

/* is_zero:
 *	Check if the string is zero a 0 to avoid 0 +0 -0 duplicates
 *	and 0 0000 +000 -00000000 too.
 *	return 1 if the argument is zero, 0 if contain
 *	anything else than a zero.
 *	or you can handel it with atoi();
*/
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

/*	is_empty:
*	check if the string is empty like "" or "          "
*	return 1 if the argument is not empty is contained anything else espace
*	0 if it empty;
*/
int	is_empty(char *av)
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

/*	is_duplicates:
*    check if the string is has a duplicate argument
*	return 1 if the argument is duplicated else 0
*/
static int	is_duplicates(char **av)
{
	int	i;
	int	j;

	i = -1;
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

	i = -1;
	nb_zero = 0;
	if (is_duplicates(av))
		return (0);
	while (av[++i])
	{
		if (!arg_is_nb(av[i]))
			return (0);
		nb_zero += is_zero(av[i]);
	}
	if (nb_zero > 1)
		return (0);
	return (1);
}
