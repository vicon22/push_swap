/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 22:42:00 by                   #+#    #+#             */
/*   Updated: 2021/10/11 14:28:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	ans;
	int			zn;

	ans = 0;
	zn = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			zn = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ans = ans * 10 + *str - '0';
		str++;
	}
	ans = ans * zn;
	if (ans > INT_MAX)
		return (1);
	if (ans < INT_MIN)
		return (-1);
	return (ans);
}
