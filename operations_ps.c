/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:59:25 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/24 19:07:41 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap_function(t_all *all, char *line)
{
	t_stack	*list_a;
	t_stack	*list_b;

	list_a = all->stack_a;
	list_b = all->stack_b;
	if (line[1] == 'a')
	{
		write(1, "sa\n", 3);
		swap_list(&list_a);
	}
	if (line[1] == 'b')
	{
		write(1, "sb\n", 3);
		swap_list(&list_b);
	}
	if (line[1] == 's')
	{
		write(1, "ss\n", 3);
		swap_list(&list_a);
		swap_list(&list_b);
	}
}

t_stack	*rotate_function(t_all *all, char c)
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

t_stack	*rev_rotate_function(t_all *all, char c)
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

void	exec_instructions(t_all *all, char *line)
{
	if (line[0] == 'r' && ft_strlen(line) == 2)
		apply_rotate(all, line);
	if (line[0] == 's')
		swap_function(all, line);
	if (line[0] == 'r' && ft_strlen(line) == 3)
		apply_reverse(all, line);
	if (line[0] == 'p')
		apply_push(all, line);
}
