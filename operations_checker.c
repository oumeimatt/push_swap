/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:59:25 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/25 12:57:33 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap_function_check(t_all *all, char *line)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = all->stack_a;
	list_b = all->stack_b;
	if (line[1] == 'a')
		swap_list(&list_a);
	if (line[1] == 'b')
		swap_list(&list_b);
	if (line[1] == 's')
	{
		swap_list(&list_a);
		swap_list(&list_b);
	}
}

t_stack	*rotate_function_check(t_all *all, char c)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = all->stack_a;
	list_b = all->stack_b;
	if (c == 'a')
	{
		rotate_list(&list_a, 1);
		return (list_a);
	}
	if (c == 'b')
	{
		rotate_list(&list_b, 1);
		return (list_b);
	}
	return (NULL);
}

t_stack	*rev_rotate_function_check(t_all *all, char c)
{
	t_stack	*list_a;
	t_stack	*list_b;
	int		count;

	list_a = all->stack_a;
	list_b = all->stack_b;
	if (c == 'a')
	{
		count = count_list(list_a);
		rotate_list(&list_a, count - 1);
		return (list_a);
	}
	if (c == 'b')
	{
		count = count_list(list_b);
		rotate_list(&list_b, count - 1);
		return (list_b);
	}
	return (NULL);
}

void	exec_instructions_check(t_all *all, char *line)
{
	if (line[0] == 'r' && ft_strlen(line) == 2)
	{
		if (line[1] == 'a')
			all->stack_a = rotate_function_check(all, 'a');
		if (line[1] == 'b')
			all->stack_b = rotate_function_check(all, 'b');
		if (line[1] == 'r')
		{
			all->stack_a = rotate_function_check(all, 'a');
			all->stack_b = rotate_function_check(all, 'b');
		}
	}
	if (line[0] == 's')
		swap_function_check(all, line);
	help_exec_check(all, line);
}

void	help_exec_check(t_all *all, char *line)
{
	if (line[0] == 'r' && ft_strlen(line) == 3)
	{
		if (line[2] == 'a')
			all->stack_a = rev_rotate_function_check(all, 'a');
		if (line[2] == 'b')
			all->stack_b = rev_rotate_function_check(all, 'b');
		if (line[2] == 'r')
		{
			all->stack_a = rev_rotate_function_check(all, 'a');
			all->stack_b = rev_rotate_function_check(all, 'b');
		}
	}
	if (line[0] == 'p')
	{
		if (line[1] == 'b')
			push_to_other_stack(&all->stack_a, &all->stack_b);
		else
			push_to_other_stack(&all->stack_b, &all->stack_a);
	}
}