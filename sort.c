/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:51:07 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/24 19:07:53 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_5_numbers(t_all *all)
{
	t_stack	*list_b;
	int		min;

	min = smallest_element(all->stack_a);
	push_min_to_b(all, min);
	min = smallest_element(all->stack_a);
	push_min_to_b(all, min);
	sort_3_numbers(all);
	list_b = all->stack_b;
	if (list_b->data < list_b->next->data)
	{
		exec_instructions(all, "sb");
	}
	exec_instructions(all, "pa");
	exec_instructions(all, "pa");
}

void	sort_4_numbers(t_all *all)
{
	t_stack	*list_b;
	int		min;

	min = smallest_element(all->stack_a);
	push_min_to_b(all, min);
	sort_3_numbers(all);
	list_b = all->stack_b;
	exec_instructions(all, "pa");
}

void	sort_function(t_all *all)
{
	t_stack	*list_a;
	t_stack	*list_b ;
	int		min;
	int		max;
	int		range;

	min = smallest_element(all->stack_a);
	max = largest_element(all->stack_a);
	range = min;
	while (all->stack_a != NULL)
	{
		list_a = all->stack_a;
		while (list_a != NULL)
		{
			if (list_a->data <= range)
			{
				push_min_to_b(all, list_a->data);
			}
			list_a = list_a->next;
		}
		range += 30;
	}
	back_to_stack_a(all);
}

void	back_to_stack_a(t_all *all)
{
	t_stack	*list_b;
	int		max;

	list_b = all->stack_b;
	while (list_b != NULL)
	{
		max = largest_element(all->stack_b);
		push_max_to_a(all, max);
		list_b = all->stack_b;
	}
}
