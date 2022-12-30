/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:16:12 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/30 18:43:19 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
	buffer[i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

void	write_a(t_list *a, t_list *b, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		push_a(a, b);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate_a(a);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate_a(a);
	else
		swap_a(a);
}

void	write_b(t_list *a, t_list *b, char *line)
{
	if (!ft_strncmp(line, "pb\n", 3))
		push_b(a, b);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate_b(b);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate_b(b);
	else
		swap_b(b);
}

void	write_d(t_list *a, t_list *b, char *line)
{
	if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b);
	else
		reverse_rr(a, b);
}

void	checker(t_list *a, t_list *b)
{
	char	*line;

	while (get_next_line(&line))
	{
		if (!line)
			break ;
		if (!ft_strncmp(line, "pa\n", 3) || !ft_strncmp(line, "ra\n", 3)
			|| !ft_strncmp(line, "rra\n", 4) || !ft_strncmp(line, "sa\n", 3))
			write_a(a, b, line);
		else if (!ft_strncmp(line, "pb\n", 3) || !ft_strncmp(line, "rb\n", 3)
			|| !ft_strncmp(line, "rrb\n", 4) || !ft_strncmp(line, "sb\n", 3))
			write_b(a, b, line);
		else if (!ft_strncmp(line, "rr\n", 3) || !ft_strncmp(line, "rrr\n", 4)
			|| !ft_strncmp(line, "ss\n", 3))
			write_d(a, b, line);
		else
			errore();
		free(line);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	char	**tab;

	tab = fill_tab(av, &size, ac);
	if (!is_corr_inp(tab))
		exit_error(NULL, NULL);
	stack_a = fill_stack_content(size, tab);
	stack_b = NULL;
	checker(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
