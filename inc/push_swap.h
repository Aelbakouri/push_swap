/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:19:56 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/29 15:51:18 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}	t_list;

/* push_swap */
int			stack_is_sorted(t_list *stack);
void		sort_tree(t_list **stack);
void		push_and_save_three(t_list **stack_a, t_list **stack_b);
void		sort(t_list **stack_a, t_list **stack_b);
void		get_cost(t_list **stack_a, t_list **stack_b);
void		cheapest_move(t_list **stack_a, t_list **stack_b);
int			lowest_index_position(t_list **stack);
void		target_position(t_list **a, t_list **b);
void		move(t_list **a, t_list **b, int cost_a, int cost_b);

/* initialization */

t_list		*fill_stack_content(int ac, char **av);
void		assign_index(t_list *stack_a, int stack_size);

/* stcak */

t_list		*ft_stack_bottom(t_list *stack);
t_list		*ft_stack_before_bottom(t_list *stack);
t_list		*stack_new(int content);
int			ft_stack_size(t_list	*stack);
void		ft_stack_add_back(t_list **stack, t_list *new);

/* string utils */

void		ft_putstr(char *str);
long int	ft_atoi(const char *str);
char		**ft_split(char *str, char sep, int *size);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);

/* ultils */

void		free_stack(t_list **stack);
void		exit_error(t_list **stack_a, t_list **stack_b);
long int	ft_atoi(const char *str);
int			nb_abs(int nb);

/* Operations */

void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
/* input check */

int			is_corr_inp(char **av);
int			is_empty(char *av);
int			is_digit(char c);
int			is_sign(char c);
int			nb_cmp(const char *s1, const char *s2);

#endif
