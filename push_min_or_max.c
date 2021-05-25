/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_min_or_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:49:13 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/25 14:41:45 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_min_to_b(t_all *all, int value)
{
	t_stack	*list_a;
	int		pos;
	int		size;

	list_a = all->stack_a;
	size = count_list(list_a);
	pos = find_value_position(all->stack_a, value);
	if (pos <= 2)
	{
		if (pos > 1)
			exec_instructions(all, "sa");
		exec_instructions(all, "pb");
	}
	else
		push_min_to_b_2(all, size, pos);
}

void	push_min_to_b_2(t_all *all, int size, int pos)
{
	if ((even_or_odd(size) == 1 && pos <= (size / 2) + 1)
		|| (even_or_odd(size) == 0 && pos <= size / 2))
	{
		while (pos > 1)
		{
			exec_instructions(all, "ra");
			pos--;
		}
	}
	else if ((even_or_odd(size) == 1 && pos > (size / 2))
		|| (even_or_odd(size) == 0 && pos > (size / 2)))
	{
		while (pos <= size)
		{
			exec_instructions(all, "rra");
			pos++;
		}
	}
	exec_instructions(all, "pb");
}

void	push_max_to_a(t_all *all, int value)
{
	t_stack	*list_b;
	int		pos;
	int		size;

	list_b = all->stack_b;
	size = count_list(all->stack_b);
	pos = find_value_position(all->stack_b, value);
	if (pos <= 2)
	{
		if (pos > 1)
			exec_instructions(all, "sb");
		exec_instructions(all, "pa");
	}
	else
		push_max_to_a_2(all, size, pos);
}

void	push_max_to_a_2(t_all *all, int size, int pos)
{
	if ((even_or_odd(size) == 1 && pos <= (size / 2) + 1)
		|| (even_or_odd(size) == 0 && pos <= size / 2))
	{
		while (pos > 1)
		{
			exec_instructions(all, "rb");
			pos--;
		}
	}
	else if ((even_or_odd(size) == 1 && pos > (size / 2))
		|| (even_or_odd(size) == 0 && pos > (size / 2)))
	{
		while (pos <= size)
		{
			exec_instructions(all, "rrb");
			pos++;
		}
	}
	exec_instructions(all, "pa");
}