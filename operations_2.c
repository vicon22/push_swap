/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:26:25 by eveiled           #+#    #+#             */
/*   Updated: 2021/10/31 17:26:25 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_list **lst)
{
	t_list	*saver1;
	t_list	*last;

	saver1 = *lst;
	*lst = (*lst)->next;
	saver1->next = NULL;
	last = ft_lstlast(*lst);
	last->next = saver1;
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_list **lst)
{
	t_list	*saver1;
	t_list	*last;

	saver1 = *lst;
	*lst = (*lst)->next;
	saver1->next = NULL;
	last = ft_lstlast(*lst);
	last->next = saver1;
	write(1, "rb\n", 3);
}

void	ft_rotate_both(t_list **lst1, t_list **lst2)
{
	t_list	*saver1;
	t_list	*last;

	saver1 = *lst1;
	*lst1 = (*lst1)->next;
	saver1->next = NULL;
	last = ft_lstlast(*lst1);
	last->next = saver1;
	saver1 = *lst2;
	*lst2 = (*lst2)->next;
	saver1->next = NULL;
	last = ft_lstlast(*lst2);
	last->next = saver1;
	write(1, "rr\n", 3);
}
