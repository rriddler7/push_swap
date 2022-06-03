/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:18:34 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:18:38 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_a(t_str **a)
{
	t_str	*tmp;
	t_str	*last;

	tmp = (*a)->next;
	last = getlast(*a);
	last->next = (*a);
	(*a)->next = NULL;
	(*a) = tmp;
}

static void	rotate_b(t_str **b)
{
	t_str	*tmp;
	t_str	*last;

	tmp = (*b)->next;
	last = getlast(*b);
	last->next = (*b);
	(*b)->next = NULL;
	(*b) = tmp;
}

void	rotate(t_stacks *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
	{
		rotate_a(&stack->a);
		write(1, "ra\n", 3);
	}
	else if (c == 'b' && stack->b && stack->b->next)
	{
		rotate_b(&stack->b);
		write(1, "rb\n", 3);
	}
	else if (c == 'r')
	{
		rotate_a(&stack->a);
		rotate_b(&stack->b);
		write(1, "rr\n", 3);
	}
}
