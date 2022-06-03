/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 17:19:56 by rriddler          #+#    #+#             */
/*   Updated: 2021/10/16 17:20:02 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_str
{
	int				value;
	int				order;
	struct s_str	*next;
}					t_str;

typedef struct s_stacks
{
	t_str	*a;
	t_str	*b;
	t_str	*copy;
}				t_stacks;

int		ft_lstsize(t_str *stack);
void	ft_lstadd_back(t_str **lst, t_str *new);
t_str	*getlast(t_str *head);
t_str	*getlastbutone(t_str *head);
void	write_error(int x);
int		ft_spaces(const char *str);
int		push_atoi(const char *str);
int		parse(int argc, char **argv);
void	duplicate_error(int argc, char **argv);
void	rotate(t_stacks *stack, char c);
void	swap(t_stacks *stack, char c);
void	reverse_rotate(t_stacks *stack, char c);
void	push_ab(t_stacks *stack, char c);
int		unsorted(t_str *tmp);
t_str	*bubble_sort(t_str *stack);
void	find_order(t_str *sort, t_str *unsort);
void	three_sort(t_str *first, t_str *second, t_str *third, t_stacks *stack);
void	five_sort(t_stacks *stack, int size);
int		maxorder_b(t_stacks *stack);
int		max_order_pos(t_stacks *stack, int max_order);
void	sorting(t_stacks *stack);
int		main(int argc, char **argv);

#endif
