/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_order.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:15:51 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:16:02 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	unsorted(t_str *tmp)
{
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		else
			tmp = tmp->next;
	}
	return (0);
}

void	ft_swap(int *value1, int *value2)
{
	int	tmp_value;

	tmp_value = *value1;
	*value1 = *value2;
	*value2 = tmp_value;
}

t_str	*getnth(t_str *head, int n)
{
	int	counter;

	counter = 0;
	while (counter < n && head)
	{
		head = head->next;
		counter++;
	}
	return (head);
}

t_str	*bubble_sort(t_str *stack)
{
	int		i;
	int		j;
	t_str	*tmp;
	size_t	size;

	i = -1;
	tmp = stack;
	size = ft_lstsize(stack);
	while (++i < (int)size)
	{
		j = i;
		while (++j < (int)size)
			if (getnth(tmp, i)->value > getnth(tmp, j)->value)
				ft_swap(&(getnth(tmp, i)->value), &(getnth(tmp, j)->value));
	}
	return (stack);
}

void	find_order(t_str *sort, t_str *unsort)
{
	int	i;

	while (unsort)
	{
		i = 0;
		while (unsort->value != getnth(sort, i)->value)
			i++;
		unsort->order = i;
		unsort = unsort->next;
	}
}
