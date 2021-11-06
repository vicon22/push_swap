/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:03:43 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:13:27 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*cr_corrent_obg(int num)
{
	int	*number;

	number = (int *)malloc(sizeof(int));
	*number = num;
	return (number);
}

static t_list	*ft_cr_copy_list(t_list **lst_a, int min, int max)
{
	t_list	*lst_copy;
	t_list	*saver;

	saver = *lst_a;
	lst_copy = ft_lstnew(cr_corrent_obg(*(int *)saver->content));
	saver = saver->next;
	while (saver)
	{
		if (*(int *)saver->content <= max && *(int *)saver->content >= min)
		{
			ft_lstadd_back(&lst_copy,
				ft_lstnew(cr_corrent_obg(*(int *)saver->content)));
		}
		saver = saver->next;
	}
	return (lst_copy);
}

static void	ft_sort_list(t_list *lst_copy)
{
	t_list	*saver1;
	t_list	*saver2;
	void	*content_saver;

	saver1 = lst_copy;
	while (saver1)
	{
		saver2 = saver1->next;
		while (saver2)
		{
			if (*(int *)(saver1->content) > *(int *)(saver2->content))
			{
				content_saver = saver1->content;
				saver1->content = saver2->content;
				saver2->content = content_saver;
			}
			saver2 = saver2->next;
		}
		saver1 = saver1->next;
	}
}

static t_list	*ft_find_elem(t_list *lst_copy, int half_size)
{
	int	i;

	i = 0;
	while (i < half_size)
	{
		i++;
		lst_copy = lst_copy->next;
	}
	return (lst_copy);
}

int	ft_find_median(t_list **lst_a, int min, int max)
{
	int		size;
	int		median;
	t_list	*lst_copy;

	lst_copy = ft_cr_copy_list(lst_a, min, max);
	ft_sort_list(lst_copy);
	size = ft_lstsize(lst_copy);
	median = *(int *)ft_find_elem(lst_copy, size / 2)->content;
	ft_lst_dell_all(lst_copy);
	return (median);
}
