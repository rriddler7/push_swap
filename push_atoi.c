/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:19:32 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:19:37 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(int x)
{
	write(1, "Error\n", 6);
	exit(x);
}

int	ft_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	push_atoi(const char *str)
{
	int		i;
	int		plm;
	long	nmb;

	i = 0;
	plm = 1;
	nmb = 0;
	ft_spaces(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			plm = -plm;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nmb = nmb * 10 + str[i] - '0';
		i++;
		if (nmb > 2147483647 || nmb < -2147483648)
			write_error(4);
	}
	nmb = nmb * plm;
	return ((int)nmb);
}
