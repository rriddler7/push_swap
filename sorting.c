/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:20:19 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:20:22 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_str *first, t_str *second, t_str *third, t_stacks *stack)
{
	if (first->value > third->value && second->value < third->value)
		rotate(stack, 'a');
	if (first->value < second->value && first->value > third->value)
		reverse_rotate(stack, 'a');
	if (first->value > second->value && first->value < third->value)
		swap(stack, 'a');
	if (first->value < second->value && first->value < third->value)
	{
		reverse_rotate(stack, 'a');
		swap(stack, 'a');
	}
	if (first->value > second->value && second->value > third->value)
	{
		rotate(stack, 'a');
		swap(stack, 'a');
	}
}

void	five_sort(t_stacks *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 3)
	{
		if (stack->a->order < size - 3)
		{
			push_ab(stack, 'b');
			i++;
		}
		reverse_rotate(stack, 'a');
	}
	if (unsorted(stack->a))
		three_sort(stack->a, stack->a->next, stack->a->next->next, stack);
	if (!unsorted(stack->b))
		rotate(stack, 'b');
	while (stack->b)
		push_ab(stack, 'a');
}

int	maxorder_b(t_stacks *stack)
{
	int		i;
	t_str	*tmp;

	tmp = stack->b;
	i = tmp->order;
	while (tmp)
	{
		if (i < tmp->order)
			i = tmp->order;
		tmp = tmp->next;
	}
	return (i);
}

int	max_order_pos(t_stacks *stack, int max_order)
{
	int		pos;
	t_str	*tmp;

	pos = 1;
	tmp = stack->b;
	while (tmp)
	{
		if (tmp->order == max_order)
			break ;
		else
		{
			pos++;
			tmp = tmp->next;
		}
	}
	return (pos);
}
