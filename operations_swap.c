/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:18:52 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:18:57 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_a(t_str **a)
{
	t_str	*first;
	t_str	*second;

	if (!a || !(*a) || !((*a)->next))
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

static void	swap_b(t_str **b)
{
	t_str	*first;
	t_str	*second;

	if (!b || !(*b) || !((*b)->next))
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	swap(t_stacks *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
	{
		swap_a(&stack->a);
		write(1, "sa\n", 3);
	}
	else if (c == 'b' && stack->b && stack->b->next)
	{
		swap_b(&stack->b);
		write(1, "sb\n", 3);
	}
	else if (c == 's')
	{
		swap_a(&stack->a);
		swap_b(&stack->b);
		write(1, "ss\n", 3);
	}
}
