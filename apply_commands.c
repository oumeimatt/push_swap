/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:21:12 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/24 19:06:03 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	apply_rotate(t_all *all, char *line)
{
	if (line[1] == 'a')
	{
		write(1, "ra\n", 3);
		all->stack_a = rotate_function(all, 'a');
	}
	if (line[1] == 'b')
	{
		write(1, "rb\n", 3);
		all->stack_b = rotate_function(all, 'b');
	}
	if (line[1] == 'r')
	{
		write(1, "rr\n", 3);
		all->stack_a = rotate_function(all, 'a');
		all->stack_b = rotate_function(all, 'b');
	}
}

void	apply_reverse(t_all *all, char *line)
{
	if (line[2] == 'a')
	{
		write(1, "rra\n", 4);
		all->stack_a = rev_rotate_function(all, 'a');
	}
	if (line[2] == 'b')
	{
		write(1, "rrb\n", 4);
		all->stack_b = rev_rotate_function(all, 'b');
	}
	if (line[2] == 'r')
	{
		write(1, "rrr\n", 4);
		all->stack_a = rev_rotate_function(all, 'a');
		all->stack_b = rev_rotate_function(all, 'b');
	}
}

void	apply_push(t_all *all, char *line)
{
	if (line[1] == 'b')
	{
		write(1, "pb\n", 3);
		push_to_other_stack(&all->stack_a, &all->stack_b);
	}
	else
	{
		write(1, "pa\n", 3);
		push_to_other_stack(&all->stack_b, &all->stack_a);
	}
}
