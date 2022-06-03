/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:19:14 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:19:18 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			return ;
		i++;
	}
	write_error(1);
}

static void	parse_str(const char *str)
{
	size_t	i;
	int		nmb;
	int		plm;

	i = 0;
	nmb = 0;
	plm = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nmb++;
		else if (((str[i] == '+' || str[i] == '-')
				&& (plm == 0 && nmb == 0)) && (str[i + 1] != '\0'))
			plm++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (plm != 0 && nmb == 0)
				write_error(2);
			nmb = 0;
			plm = 0;
		}
		else
			write_error(3);
		i++;
	}
}

int	parse(int argc, char **argv)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_spaces(argv[i]))
		{
			parse_number(argv[i]);
			parse_str(argv[i]);
			flag = 1;
		}
		i++;
	}
	return (flag);
}

static int	duplicate(int **nmb, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (nmb[0][i] == nmb[0][j])
				return (1);
		}
	}
	return (0);
}

void	duplicate_error(int argc, char **argv)
{
	int			j;
	int			*mass_nmb;

	j = 1;
	mass_nmb = malloc(sizeof(int) * (argc - 1));
	while (j < argc)
	{
		mass_nmb[j - 1] = push_atoi(argv[j]);
		j++;
	}
	if (duplicate(&mass_nmb, argc) == 1)
		write_error(5);
	free(mass_nmb);
}
