/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_new_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:33:53 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:36:39 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_less_index(t_list **lst_a, t_list **lst_b)
{
	int		i;
	int		j;
	int		min;
	int		current;
	t_list	*saver;

	i = 0;
	j = 0;
	saver = *lst_b;
	min = ft_count_less_step(lst_a, lst_b, saver);
	while (saver)
	{
		current = ft_count_less_step(lst_a, lst_b, saver);
		if (current < min)
			j = i;
		saver = saver->next;
		i++;
	}
	return (j);
}

void	ft_rotate_all_b(t_list **lst_a, t_list **lst_b, int i_b)
{
	int	size_b;

	(void)lst_a;
	size_b = ft_lstsize(*lst_b);
	if (i_b <= size_b / 2)
	{
		while (i_b-- > 0)
			ft_rotate_b(lst_b);
	}
	else
	{
		while (i_b++ < size_b)
			ft_reverse_rotate_b(lst_b);
	}
}

void	ft_rotate_all_a(t_list **lst_a, t_list **lst_b, int current_value)
{
	int	size_a;
	int	i_a;

	(void)lst_b;
	size_a = ft_lstsize(*lst_a);
	i_a = ft_find_place_in_a(lst_a, current_value);
	if (i_a <= size_a / 2)
	{
		while (i_a-- > 0)
			ft_rotate_a(lst_a);
	}
	else
	{
		while (i_a++ < size_a)
			ft_reverse_rotate_a(lst_a);
	}
}

//void	ft_count_for_rotate_both(int *i_a, int *i_b,
//			t_list **lst_a, t_list **lst_b)
//{
//	while (*i_a > 0 && *i_b > 0)
//	{
//		(*i_a)--;
//		(*i_b)--;
//		ft_rotate_both(lst_a, lst_b);
//	}
//}
//
//void	ft_count_for_reverse_rotate_both(int *i_a, int *i_b,
//			t_list **lst_a, t_list **lst_b)
//{
//	(*i_a)++;
//	(*i_b)++;
//	ft_reverse_rotate_both(lst_a, lst_b);
//}

void	ft_rotate_a_b_together(t_list **lst_a, t_list **lst_b,
				int current_value, int i_b)
{
	int	size_a;
	int	size_b;
	int	i_a;

	size_a = ft_lstsize(*lst_a);
	size_b = ft_lstsize(*lst_b);
	i_a = ft_find_place_in_a(lst_a, current_value);
	if (i_a <= size_a / 2 && i_b <= size_b / 2)
	{
		ft_count_for_rotate_both(&i_a, &i_b, lst_a, lst_b);
	}
	if (i_a > size_a / 2 && i_b > size_b / 2)
	{
		while (i_a < size_a && i_b < size_b)
		{
			ft_count_for_reverse_rotate_both(&i_a, &i_b, lst_a, lst_b);
		}
	}
	ft_rotate_all_b(lst_a, lst_b, i_b);
	ft_rotate_all_a(lst_a, lst_b, current_value);
}

void	ft_push_back(t_list **lst_a, t_list **lst_b)
{
	int	current_value;
	int	i;

	while (*lst_b)
	{
		i = ft_count_less_index(lst_a, lst_b);
		current_value = *(int *)find_elem_by_index(lst_b, i)->content;
		ft_rotate_a_b_together(lst_a, lst_b, current_value, i);
		i = ft_count_less_index(lst_a, lst_b);
		current_value = *(int *)find_elem_by_index(lst_b, i)->content;
		ft_rotate_all_b(lst_a, lst_b, i);
		ft_rotate_all_a(lst_a, lst_b, current_value);
		ft_push_a(lst_a, lst_b);
	}
}
