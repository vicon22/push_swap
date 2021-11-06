/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveiled <eveiled@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:41:58 by eveiled           #+#    #+#             */
/*   Updated: 2021/11/05 16:41:58 by eveiled          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nbrlen(int number)
{
	int	counter;

	counter = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		counter++;
	while (number != 0)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}

void	ft_check_argv(int argc, char **argv)
{
	int		i;
	int		j;
	int		number;
	char	**all;

	i = 0;
	j = 1;
	if (argc < 2 || argv[1][0] == '\0' || (argv[1][0] == ' ' && argv[1][1] == '\0' && argc == 2))
	{
		write(1, "Plz, enter parameters!\n", 23);
		exit (1);
	}
	while (j < argc)
	{
		all = ft_split(argv[j], ' ');
		i = 0;
//		if (all[0] == NULL)
//		{
//			printf("--\n");
//			all = ft_split(argv[++j], ' ');
//		}
		while (all[i] != NULL)
		{
			number = ft_atoi(all[i]);
			if (((int) ft_strlen(all[i]) != ft_nbrlen(number)) || (number == 0 && all[i][0] != '0'))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			i++;
		}
		ft_free_all_split(all);
		j++;
	}
}
