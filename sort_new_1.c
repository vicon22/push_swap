/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:26:47 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:28:21 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_list **lst_b)
{
	int		max;
	t_list	*saver;

	saver = *lst_b;
	max = *(int *)saver->content;
	while (saver)
	{
		if (*(int *)saver->content > max)
			max = *(int *)saver->content;
		saver = saver->next;
	}
	return (max);
}

int	ft_find_min(t_list **lst_b)
{
	int		min;
	t_list	*saver;

	saver = *lst_b;
	min = *(int *)saver->content;
	while (saver)
	{
		if (*(int *)saver->content < min)
			min = *(int *)saver->content;
		saver = saver->next;
	}
	return (min);
}

int	find_elem(t_list **lst, int number)
{
	int		index;
	t_list	*saver;

	index = 0;
	saver = *lst;
	while (saver)
	{
		if (*(int *)saver->content == number)
			return (index);
		index++;
		saver = saver->next;
	}
	return (-1);
}

t_list	*find_elem_by_index(t_list **lst, int index)
{
	t_list	*saver;

	saver = *lst;
	while (index)
	{
		index--;
		saver = saver->next;
	}
	return (saver);
}

int	ft_find_suif_elems(t_list **lst_a, int min, int max, int median)
{
	int		i;
	t_list	*saver;

	i = 0;
	saver = *lst_a;
	while (saver)
	{
		if (*(int *)saver->content < max && *(int *)saver->content > min
			&& *(int *)saver->content != median)
		{
			return (i);
		}
		i++;
		saver = saver->next;
	}
	return (-1);
}
