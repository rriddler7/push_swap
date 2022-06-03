/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:16:25 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:16:31 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fromarray(t_str **head, int arr, size_t size)
{
	t_str	*tmp;

	if (size == 0)
		return ;
	tmp = (t_str *)malloc(sizeof(t_str));
	if (tmp != NULL)
	{
		tmp->value = arr;
		tmp->order = 0;
		tmp->next = NULL;
	}
	if (*head)
		ft_lstadd_back(head, tmp);
	else
		*head = tmp;
}

static void	create_stack(t_stacks *stack)
{
	t_str	*a_str;
	t_str	*b_str;
	t_str	*copy_str;

	a_str = NULL;
	b_str = NULL;
	copy_str = NULL;
	stack->a = a_str;
	stack->b = b_str;
	stack->copy = copy_str;
}

static void	free_stack(t_str *head)
{
	t_str	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	int			i;
	int			nmb;
	t_stacks	stack;
	t_str		*tmp;

	i = 0;
	create_stack(&stack);
	if (parse(argc, argv))
	{
		duplicate_error(argc, argv);
		while (argv[++i])
		{
			nmb = push_atoi(argv[i]);
			fromarray(&(stack.a), nmb, argc);
			fromarray(&(stack.copy), nmb, argc);
		}
		tmp = bubble_sort(stack.copy);
		find_order(tmp, stack.a);
		if (unsorted(stack.a))
			sorting(&stack);
	}
	free_stack(stack.a);
	free_stack(stack.copy);
	return (0);
}
