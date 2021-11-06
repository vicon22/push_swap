/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:26:36 by eveiled           #+#    #+#             */
/*   Updated: 2021/10/31 17:26:36 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstpenult(t_list *lst)
{
	t_list	*saver1;

	saver1 = lst;
	while (lst->next)
	{
		saver1 = lst;
		lst = lst->next;
	}
	return (saver1);
}

void	ft_reverse_rotate_a(t_list **lst)
{
	t_list	*saver1;
	t_list	*saver2;
	t_list	*last;

	saver1 = *lst;
	last = ft_lstlast(*lst);
	saver2 = ft_lstpenult(*lst);
	saver2->next = NULL;
	saver1 = *lst;
	*lst = last;
	(*lst)->next = saver1;
	write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_list **lst)
{
	t_list	*saver1;
	t_list	*saver2;
	t_list	*last;

	saver1 = *lst;
	last = ft_lstlast(*lst);
	saver2 = ft_lstpenult(*lst);
	saver2->next = NULL;
	saver1 = *lst;
	*lst = last;
	(*lst)->next = saver1;
	write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_both(t_list **lst1, t_list **lst2)
{
	t_list	*saver1;
	t_list	*saver2;
	t_list	*last;

	last = ft_lstlast(*lst1);
	saver2 = ft_lstpenult(*lst1);
	saver2->next = NULL;
	saver1 = *lst1;
	*lst1 = last;
	(*lst1)->next = saver1;
	last = ft_lstlast(*lst2);
	saver2 = ft_lstpenult(*lst2);
	saver2->next = NULL;
	saver1 = *lst2;
	*lst2 = last;
	(*lst2)->next = saver1;
	write(1, "rrr\n", 4);
}
