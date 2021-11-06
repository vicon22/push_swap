/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:37:21 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:36:39 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_finally_sort_a(t_list **lst_a)
{
	int	min;
	int	index;
	int	size_a;

	min = ft_find_min(lst_a);
	index = find_elem(lst_a, min);
	size_a = ft_lstsize(*lst_a);
	if (index <= size_a / 2)
	{
		while (index-- > 0)
			ft_rotate_a(lst_a);
	}
	else
	{
		while (index++ < size_a)
			ft_reverse_rotate_a(lst_a);
	}
}

void	ft_half_of_separator(t_list *saver, int median_half,
			t_list **lst_a, t_list **lst_b)
{
	if (*(int *)saver->content >= median_half && *lst_b)
	{
		ft_push_b(lst_a, lst_b);
		ft_rotate_b(lst_b);
	}
	else
		ft_push_b(lst_a, lst_b);
}

void	ft_separator(t_list **lst_a, t_list **lst_b,
			int max, int median)
{
	int		i;
	int		size;
	int		min;
	int		median_half;
	t_list	*saver;

	size = ft_lstsize(*lst_a);
	saver = *lst_a;
	median_half = ft_find_median(lst_a, median, max);
	min = ft_find_min(lst_a);
	i = 0;
	while (i < size)
	{
		if (*(int *)saver->content < max && *(int *)saver->content > min
			&& *(int *)saver->content > median)
		{
			ft_half_of_separator(saver, median_half, lst_a, lst_b);
		}
		else
			ft_rotate_a(lst_a);
		i++;
		saver = *lst_a;
	}
}

void	ft_push_between_3(t_list **lst_a, t_list **lst_b, int min, int max)
{
	int	median;
	int	median_half;
	int	median_half_half;

	median = ft_find_median(lst_a, min, max);
	median_half = ft_find_median(lst_a, median, max);
	ft_separator(lst_a, lst_b, max, median_half);
	median_half_half = ft_find_median(lst_a, median, median_half);
	ft_separator(lst_a, lst_b, max, median_half_half);
	ft_separator(lst_a, lst_b, max, ft_find_median(lst_a, min, median));
	ft_push_between(lst_a, lst_b, min, max);
}

void	ft_push_between_4(t_list **lst_a, t_list **lst_b, int min, int max)
{
	int	median;
	int	median_half;
	int	median_half_half;

	median = ft_find_median(lst_a, min, max);
	median_half = ft_find_median(lst_a, median, max);
	median_half_half = ft_find_median(lst_a, median_half, max);
	ft_separator(lst_a, lst_b, max, median_half_half);
	ft_separator(lst_a, lst_b, max,
		ft_find_median(lst_a, median_half, median_half_half));
	median_half_half = ft_find_median(lst_a, median, median_half);
	ft_separator(lst_a, lst_b, max, median_half_half);
	ft_separator(lst_a, lst_b, max,
		ft_find_median(lst_a, median, median_half_half));
	median = ft_find_median(lst_a, min, max);
	median_half = ft_find_median(lst_a, median, max);
	ft_separator(lst_a, lst_b, max, median_half);
	ft_separator(lst_a, lst_b, max,
		ft_find_median(lst_a, median, median_half));
	ft_separator(lst_a, lst_b, max, ft_find_median(lst_a, min, median));
	ft_push_between(lst_a, lst_b, min, max);
}

//void	ft_sort_big_array(t_list **lst_a, t_list **lst_b)
//{
//	int	min;
//	int	max;
//
//	min = ft_find_min(lst_a);
//	max = ft_find_max(lst_a);
//	if (ft_lstsize(*lst_a) > 20)
//		ft_push_between_3(lst_a, lst_b, min, max);
//	if (ft_lstsize(*lst_a) > 300)
//		ft_push_between_4(lst_a, lst_b, min, max);
//	ft_sort_a(lst_a, lst_b);
//	ft_push_back(lst_a, lst_b);
//	ft_finally_sort_a(lst_a);
//}
