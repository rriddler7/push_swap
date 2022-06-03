/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:18:12 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:18:16 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_a(t_str **a)
{
	t_str	*last;
	t_str	*lastbutone;

	lastbutone = getlastbutone(*a);
	last = lastbutone->next;
	last->next = (*a);
	lastbutone->next = NULL;
	(*a) = last;
}

static void	reverse_rotate_b(t_str **b)
{
	t_str	*last;
	t_str	*lastbutone;

	lastbutone = getlastbutone(*b);
	last = lastbutone->next;
	last->next = (*b);
	lastbutone->next = NULL;
	(*b) = last;
}

void	reverse_rotate(t_stacks *stack, char c)
{
	if (c == 'a' && stack->a && stack->a->next)
	{
		reverse_rotate_a(&stack->a);
		write(1, "rra\n", 4);
	}
	else if (c == 'b' && stack->b && stack->b->next)
	{
		reverse_rotate_b(&stack->b);
		write(1, "rrb\n", 4);
	}
	else if (c == 'r')
	{
		reverse_rotate_a(&stack->a);
		reverse_rotate_b(&stack->b);
		write(1, "rrr\n", 4);
	}
}
