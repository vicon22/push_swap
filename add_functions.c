/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:42:17 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:42:51 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_all_split(char **all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		free(all[i]);
		i++;
	}
	free(all);
}

void	show_all_list(t_list *list_a, t_list *list_b)
{
	printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n");
	while (list_a)
	{
		printf("content_a:%d\n", *(int *)(list_a->content));
		list_a = list_a->next;
	}
	printf("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n");
	while (list_b)
	{
		printf("content_b:%d\n", *(int *)(list_b->content));
		list_b = list_b->next;
	}
}
