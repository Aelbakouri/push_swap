/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:50 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/26 17:14:56 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
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

char	*str_ndup(char *str, unsigned int n)
{
	char				*s;
	unsigned int		i;

	i = 0;
	s = malloc(sizeof(char) * (n + 1));
	while (i < n)
		s[i++] = *str++;
	s[n] = 0;
	return (s);
}

char	**ft_split(char *str, char sep)
{
	char	**tab;
	int		count;
	int		i;
	int		j;

	count = 0;
	j = -1;
	while (str[++j])
		if ((str[j] != sep && str[j + 1] == sep)
			|| (str[j] != sep && str[j + 1] == '\0'))
			count++;
	tab = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (i < count)
	{
		j = 0;
		while (*str && *str == sep)
			str++;
		while (str[j] && str[j] != sep)
			j++;
		tab[i++] = str_ndup(str, j);
		str = str + j;
	}
	tab[i] = NULL;
	return (tab);
}
