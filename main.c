/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:43:08 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 17:43:34 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*cr_corrent_obg(char *str)
{
	int	*number;

	number = (int *)malloc(sizeof(int));
	*number = ft_atoi(str);
	return (number);
}

t_list	*ft_cr_list_a(int argc, char **argv)
{
	int		i;
	int		j;
	t_list	*lst_a;
	char	**all;

	j = 1;
	if (argv[1][0] == ' ' && argv[1][1] == '\0')
		j++;
	all = ft_split(argv[j], ' ');
	i = 0;
	if (all[i])
	{
		//printf("++\n");
		lst_a = ft_lstnew(cr_corrent_obg(all[i++]));
	}
	//printf("---\n");
	while (all[i] != NULL)
		ft_lstadd_back(&lst_a, ft_lstnew(cr_corrent_obg(all[i++])));
	ft_free_all_split(all);
	j++;
	while (j < argc)
	{
		all = ft_split(argv[j], ' ');
		i = 0;
		while (all[i] != NULL)
			ft_lstadd_back(&lst_a, ft_lstnew(cr_corrent_obg(all[i++])));
		ft_free_all_split(all);
		j++;
	}
	//printf("---\n");
	//show_all_list(lst_a, NULL);
	return (lst_a);
}

void	ft_lst_dell_all(t_list *lst_a)
{
	t_list	*saver;

	while (lst_a)
	{
		saver = lst_a;
		lst_a = lst_a->next;
		free(saver->content);
		free(saver);
	}
}

int	ft_check_duplicates(t_list *lst_a)
{
	t_list	*saver1;
	t_list	*saver2;

	saver1 = lst_a;
	while (saver1)
	{
		saver2 = lst_a;
		while (saver2)
		{
			if (*(int *)saver1->content == *(int *)saver2->content
				&& saver1 != saver2)
			{
				write(2, "Error\n", 6);
				ft_lst_dell_all(lst_a);
				exit (1);
			}
			saver2 = saver2->next;
		}
		saver1 = saver1->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;

	lst_b = NULL;
	ft_check_argv(argc, argv);
	lst_a = ft_cr_list_a(argc, argv);
	ft_check_duplicates(lst_a);
	ft_sort_big_array(&lst_a, &lst_b);
	ft_lst_dell_all(lst_a);
	ft_lst_dell_all(lst_b);
	return (0);
}

/*show_all_list(lst_a, lst_b);*/