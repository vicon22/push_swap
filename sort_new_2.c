/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:31:51 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:31:51 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_previous_last(t_list **lst_a, t_list *last)
{
	t_list	*saver;

	saver = *lst_a;
	if (saver == last)
		saver = NULL;
	while (saver)
	{
		if (saver->next == last)
			break ;
		saver = saver->next;
	}
	return (saver);
}

int	ft_find_suif_elems_diff_side(t_list **lst_a, int min, int max, int median)
{
	int		i;
	int		size;
	t_list	*saver;

	i = 0;
	saver = ft_lstlast(*lst_a);
	size = ft_lstsize(*lst_a);
	while (saver)
	{
		if (*(int *)saver->content < max && *(int *)saver->content > min
			&& *(int *)saver->content != median)
		{
			return (size - i - 1);
		}
		i++;
		saver = ft_previous_last(lst_a, saver);
	}
	return (-1);
}

void	ft_half_push_between(int current, int median,
			t_list **lst_a, t_list **lst_b)
{
	if (current > median && *lst_b)
	{
		ft_push_b(lst_a, lst_b);
		ft_rotate_b(lst_b);
	}
	else
		ft_push_b(lst_a, lst_b);
}

void	ft_push_between(t_list **lst_a, t_list **lst_b, int min, int max)
{
	int	median;
	int	i;
	int	j;
	int	size;
	int	current;

	median = ft_find_median(lst_a, min, max);
	size = ft_lstsize(*lst_a);
	while (size > 3)
	{
		i = ft_find_suif_elems(lst_a, min, max, median);
		j = ft_find_suif_elems_diff_side(lst_a, min, max, median);
		if (size - j < i)
			i = j;
		if (i <= size / 2)
			while (i-- > 0)
				ft_rotate_a(lst_a);
		else
			while (i++ < size)
				ft_reverse_rotate_a(lst_a);
		current = *(int *)(*lst_a)->content;
		ft_half_push_between(current, median, lst_a, lst_b);
		size = ft_lstsize(*lst_a);
	}
}

int	ft_find_place_in_a(t_list **lst_a, int current)
{
	int		i;
	int		size;
	t_list	*saver;
	t_list	*previous;

	i = 0;
	saver = ft_lstlast(*lst_a);
	size = ft_lstsize(*lst_a);
	while (saver)
	{
		previous = ft_previous_last(lst_a, saver);
		if (previous && *(int *)previous->content < current
			&& *(int *)saver->content > current)
		{
			return (size - i - 1);
		}
		i++;
		saver = ft_previous_last(lst_a, saver);
	}
	return (-1);
}

//int	ft_count_less_step(t_list **lst_a, t_list **lst_b, t_list *current)
//{
//	int	current_value;
//	int	size_a;
//	int	size_b;
//	int	i_a;
//	int	i_b;
//
//	current_value = *(int *)current->content;
//	size_a = ft_lstsize(*lst_a);
//	size_b = ft_lstsize(*lst_b);
//	i_a = ft_find_place_in_a(lst_a, current_value);
//	if (i_a > size_a / 2)
//	{
//		i_a = size_a - i_a;
//	}
//	i_b = find_elem(lst_b, current_value);
//	if (i_b > size_b / 2)
//	{
//		i_b = size_b - i_b;
//	}
//	return (i_a + i_b);
//}
