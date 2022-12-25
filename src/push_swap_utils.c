/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bako <ael-bako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:36:58 by ael-bako          #+#    #+#             */
/*   Updated: 2022/12/25 14:57:01 by ael-bako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/push_swap.h"

// void	ft_lstdelone(t_list *lst, void (*del)(int*))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(&lst->content);
// 	free(lst);
// }

// void	ft_lstclear(t_list **lst, void (*del)(int*))
// {
// 	t_list	*temp;
// 	t_list	*prev;

// 	temp = *lst;
// 	while (temp)
// 	{
// 		prev = temp;
// 		temp = temp->next;
// 		ft_lstdelone(prev, del);
// 	}
// 	*lst = NULL;
// }

// t_list	*ft_lstnew(int content)
// {
// 	t_list	*lnew;

// 	lnew = malloc(sizeof(t_list));
// 	if (!lnew)
// 		return (NULL);
// 	lnew -> content = content;
// 	lnew -> next = NULL;
// 	return (lnew);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	if (!lst)
// 		return ;
// 	if (*lst)
// 	{
// 		last = *lst;
// 		last = ft_lstlast(*lst);
// 		last->next = new;
// 	}
// 	else
// 		*lst = new;
// }


// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (*lst && new)
// 		new -> next = *lst;
// 	if (new)
// 		*lst = new;
// }

// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 		lst = lst->next;
// 	return (lst);
// }


// int	ft_lstsize(t_list *lst)
// {
// 	int	i;

// 	i = 0;
// 	while (lst)
// 	{
// 		lst = lst -> next;
// 		i++;
// 	}
// 	return (i);
// }

