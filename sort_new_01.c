/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:37:21 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:36:39 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_for_rotate_both(int *i_a, int *i_b,
			t_list **lst_a, t_list **lst_b)
{
	while (*i_a > 0 && *i_b > 0)
	{
		(*i_a)--;
		(*i_b)--;
		ft_rotate_both(lst_a, lst_b);
	}
}

void	ft_count_for_reverse_rotate_both(int *i_a, int *i_b,
			t_list **lst_a, t_list **lst_b)
{
	(void)lst_a;
	(void)lst_b;
	(*i_a)++;
	(*i_b)++;
}

int	ft_count_less_step(t_list **lst_a, t_list **lst_b, t_list *current)
{
	int	current_value;
	int	size_a;
	int	size_b;
	int	i_a;
	int	i_b;

	current_value = *(int *)current->content;
	size_a = ft_lstsize(*lst_a);
	size_b = ft_lstsize(*lst_b);
	i_a = ft_find_place_in_a(lst_a, current_value);
	if (i_a > size_a / 2)
	{
		i_a = size_a - i_a;
	}
	i_b = find_elem(lst_b, current_value);
	if (i_b > size_b / 2)
	{
		i_b = size_b - i_b;
	}
	return (i_a + i_b);
}

void	ft_sort_big_array(t_list **lst_a, t_list **lst_b)
{
	int	min;
	int	max;

	min = ft_find_min(lst_a);
	max = ft_find_max(lst_a);
	if (ft_lstsize(*lst_a) > 20)
		ft_push_between_3(lst_a, lst_b, min, max);
	if (ft_lstsize(*lst_a) > 300)
		ft_push_between_4(lst_a, lst_b, min, max);
	ft_sort_a(lst_a, lst_b);
	ft_push_back(lst_a, lst_b);
	ft_finally_sort_a(lst_a);
}
