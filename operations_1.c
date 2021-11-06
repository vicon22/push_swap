/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:26:33 by eveiled           #+#    #+#             */
/*   Updated: 2021/10/31 18:22:33 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **lst)
{
	t_list	*saver1;
	t_list	*saver2;

	if (*lst && (*lst)->next)
	{
		saver1 = *lst;
		saver2 = (*lst)->next;
		saver1->next = saver2->next;
		saver2->next = saver1;
		*lst = saver2;
	}
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_list **lst)
{
	t_list	*saver1;
	t_list	*saver2;

	if (*lst && (*lst)->next)
	{
		saver1 = *lst;
		saver2 = (*lst)->next;
		saver1->next = saver2->next;
		saver2->next = saver1;
		*lst = saver2;
	}
	write(1, "sb\n", 3);
}

void	ft_swap_both(t_list **lst1, t_list **lst2)
{
	t_list	*saver1;
	t_list	*saver2;

	if (*lst1 && (*lst1)->next)
	{
		saver1 = *lst1;
		saver2 = (*lst1)->next;
		saver1->next = saver2->next;
		saver2->next = saver1;
		*lst1 = saver2;
	}
	if (*lst2 && (*lst2)->next)
	{
		saver1 = *lst2;
		saver2 = (*lst2)->next;
		saver1->next = saver2->next;
		saver2->next = saver1;
		*lst2 = saver2;
	}
	write(1, "ss\n", 3);
}

void	ft_push_a(t_list **lst_2, t_list **lst_1)
{
	t_list	*saver;

	if (!*lst_2)
	{
		write(1, "pa\n", 3);
		return ;
	}
	saver = *lst_1;
	*lst_1 = (*lst_1)->next;
	saver->next = *lst_2;
	*lst_2 = saver;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_list **lst_1, t_list **lst_2)
{
	t_list	*saver;

	if (!*lst_1)
	{
		write(1, "pb\n", 3);
		return ;
	}
	saver = *lst_1;
	*lst_1 = (*lst_1)->next;
	saver->next = *lst_2;
	*lst_2 = saver;
	write(1, "pb\n", 3);
}
