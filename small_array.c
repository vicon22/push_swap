/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:19:16 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:21:32 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_sorted_a(t_list *lst_a)
{
	int		first;
	int		last;
	int		second;

	while (lst_a)
	{
		first = *(int *)lst_a->content;
		second = *(int *)lst_a->next->content;
		last = *(int *)ft_lstlast(lst_a)->content;
		if (first < second && first < last && second < last)
			lst_a = lst_a->next;
		else if (first < second && first < last && second == last)
			return (1);
		else
			break ;
	}
	return (0);
}

static void	logic_sort_a(int first, int second, int last, t_list **lst_a)
{
	if (first > second && first > last && second > last)
		ft_swap_a(lst_a);
	if (first > second && first > last && second < last)
		ft_rotate_a(lst_a);
	if (first > second && first < last && second < last)
		ft_swap_a(lst_a);
	if (first < second && first > last && second > last)
		ft_reverse_rotate_a(lst_a);
	if (first < second && first < last && second > last)
		ft_swap_a(lst_a);
}

static void	ft_swap_first_two(int first, int second, t_list **lst_a)
{
	if (first > second)
		ft_swap_a(lst_a);
}

void	ft_sort_a(t_list **lst_a, t_list **lst_b)
{
	int		first;
	int		last;
	int		second;

	while (1)
	{
		if (ft_lstsize(*lst_a) == 1)
			break ;
		first = *(int *)(*lst_a)->content;
		second = *(int *)(*lst_a)->next->content;
		if (ft_lstsize(*lst_a) == 2)
		{
			ft_swap_first_two(first, second, lst_a);
			break ;
		}
		last = *(int *)ft_lstlast(*lst_a)->content;
		logic_sort_a(first, second, last, lst_a);
		if (first < second && first < last && (second < last || second == last))
		{
			if (ft_check_sorted_a(*lst_a) == 1)
				break ;
			else
				ft_push_b(lst_a, lst_b);
		}
	}
}
