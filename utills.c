/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:20:33 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:20:37 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_str *stack)
{
	size_t	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_str **lst, t_str *new)
{
	t_str	*addnode;

	addnode = *lst;
	if (*lst == NULL)
		*lst = new;
	if (lst != NULL && addnode != NULL)
	{
		while (addnode->next)
			addnode = addnode->next;
	}
	if (addnode != NULL && new != NULL)
		addnode->next = new;
}

t_str	*getlast(t_str *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

t_str	*getlastbutone(t_str *head)
{
	if (head == NULL)
		exit(0);
	if (head->next == NULL)
		return (NULL);
	while (head->next->next)
		head = head->next;
	return (head);
}
