/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:50 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/29 22:12:26 by ael-bako         ###   ########.fr       */
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

char	**ft_split(char *str, char sep, int *size)
{
	char	**tab;
	int		count;
	int		j;

	count = 0;
	j = -1;
	while (str[++j])
		if ((str[j] != sep && str[j + 1] == sep)
			|| (str[j] != sep && str[j + 1] == '\0'))
			count++;
	tab = malloc(sizeof(char *) * (count + 1));
	*size = 0;
	while (*(size) < count)
	{
		j = 0;
		while (*str && *str == sep)
			str++;
		while (str[j] && str[j] != sep)
			j++;
		tab[(*size)++] = str_ndup(str, j);
		str = str + j;
	}
	tab[*size] = NULL;
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	str[i++] = ' ';
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
