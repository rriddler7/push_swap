/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxsorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:16:51 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:16:58 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_butterfly_pb(t_stacks *stack)
{
	int	i;

	i = 0;
	while (stack->a)
	{
		if (i > 1 && stack->a->order <= i)
		{
			push_ab(stack, 'b');
			i++;
			rotate(stack, 'b');
		}
		else if (stack->a->order <= i + 15)
		{
			push_ab(stack, 'b');
			i++;
		}
		else if (ft_lstsize(stack->a) > 1 && stack->a->order >= i)
		{
			rotate(stack, 'a');
		}
	}
}

static void	sort_butterfly_pa(t_stacks *stack)
{
	int	size_b;
	int	max_order;
	int	max_pos;

	while (stack->b)
	{
		size_b = ft_lstsize(stack->b);
		max_order = maxorder_b(stack);
		max_pos = max_order_pos(stack, max_order);
		if (max_pos == 1)
		{
			push_ab(stack, 'a');
		}
		else if (max_pos != 1 && max_pos <= size_b / 2)
		{
			if (stack->b->order != max_order)
				rotate(stack, 'b');
		}
		else if (max_pos != 1 && max_pos > size_b / 2)
		{
			if (stack->b->order != max_order)
				reverse_rotate(stack, 'b');
		}
	}
}

static void	maxsort_butterfly_pb(t_stacks *stack)
{
	int	i;

	i = 0;
	while (stack->a)
	{
		if (i > 1 && stack->a->order <= i)
		{
			push_ab(stack, 'b');
			i++;
			rotate(stack, 'b');
		}
		else if (stack->a->order <= i + 30)
		{
			push_ab(stack, 'b');
			i++;
		}
		else if (ft_lstsize(stack->a) > 1 && stack->a->order >= i)
		{
			rotate(stack, 'a');
		}
	}
}

static void	maxsort_butterfly_pa(t_stacks *stack)
{
	int	size_b;
	int	max_order;
	int	max_pos;

	while (stack->b)
	{
		size_b = ft_lstsize(stack->b);
		max_order = maxorder_b(stack);
		max_pos = max_order_pos(stack, max_order);
		if (max_pos == 1)
			push_ab(stack, 'a');
		else if (max_pos != 1 && max_pos <= size_b / 2)
		{
			if (stack->b->order != max_order)
				rotate(stack, 'b');
		}
		else if (max_pos != 1 && max_pos > size_b / 2)
		{
			if (stack->b->order != max_order)
				reverse_rotate(stack, 'b');
		}
	}
}

void	sorting(t_stacks *stack)
{
	int	size;

	size = ft_lstsize(stack->a);
	if (size == 2)
		swap(stack, 'a');
	else if (size == 3)
		three_sort(stack->a, stack->a->next, stack->a->next->next, stack);
	else if (size > 3 && size < 6)
		five_sort(stack, size);
	else if (size > 5 && size < 101)
	{
		sort_butterfly_pb(stack);
		sort_butterfly_pa(stack);
	}
	else
	{
		maxsort_butterfly_pb(stack);
		maxsort_butterfly_pa(stack);
	}
}
