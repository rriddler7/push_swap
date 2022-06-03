/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:17:44 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:17:50 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_str **a, t_str **b)
{
	t_str	*tmp;

	tmp = NULL;
	if ((*b) && (*b)->next)
		tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
}

static void	push_b(t_str **b, t_str **a)
{
	t_str	*tmp;

	tmp = NULL;
	if ((*a) && (*a)->next)
		tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
}

void	push_ab(t_stacks *stack, char c)
{
	if (c == 'a' && stack->b)
	{
		push_a(&stack->a, &stack->b);
		write(1, "pa\n", 3);
	}
	else if (c == 'b' && stack->a)
	{
		push_b(&stack->b, &stack->a);
		write(1, "pb\n", 3);
	}
}
