/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:04:42 by ael-bako          #+#    #+#             */
/*   Updated: 2023/01/06 11:22:01 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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

/* stack init*/

t_list		*ft_stack_bottom(t_list *stack);
t_list		*ft_stack_before_bottom(t_list *stack);
t_list		*stack_new(int content);
int			ft_stack_size(t_list	*stack);
void		ft_stack_add_back(t_list **stack, t_list *new);

/* string utils */

void		ft_putstr(char *str);
char		**ft_split(char *str, char sep, int *size);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char *s2);
int			str_ncmp(char *str1, char *str2, int n);

/* ultils  */

void		free_stack(t_list **stack);
void		exit_error(t_list **stack_a, t_list **stack_b);
long int	ft_atoi(const char *str);
char		**fill_tab(char **av, int *size, int ac);
int			stack_is_sorted(t_list *stack);
t_list		*fill_stack_content(int ac, char **av);

/* Operations */

void		swap(t_list **stack, char *str);
void		ss(t_list **stack_a, t_list **stack_b);
void		push(t_list **src, t_list **dest, char *str);
void		rotate(t_list **stack, char *str);
void		rr(t_list **stack_a, t_list **stack_b);
void		rrotate(t_list **stack, char *str);
void		rrr(t_list **stack_a, t_list **stack_b);
void		do_oper_a(t_list **a, t_list **b, char *line);
void		do_oper_b(t_list **a, t_list **b, char *line);

/* input check */

int			is_corr_inp(char **av);
int			is_empty(char *av);
int			is_digit(char c);
int			is_sign(char c);
int			nb_cmp(const char *s1, const char *s2);

#endif
