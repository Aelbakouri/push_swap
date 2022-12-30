/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:44:11 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/30 18:01:35 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	write(0, "-------> ", 10);
	r = read(0, &c, 1);
	while (r && r != -1 && c != '\n' && c != '\0')
	{
		buffer[i++] = c;
		r = read(0, &c, 1);
	}
	// buffer[i++] = '\n';
	buffer[i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

int main()
{
	char *str;

	while (get_next_line(&str))
	{
		if (!strcmp(str, "sa"))
			printf("%s\n", "do_sa");
		else if (!strcmp(str, "sb"))
			printf("%s\n", "do_sa");
		else
			printf("%s\n", "err");
	}


}
