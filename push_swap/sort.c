/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:51:07 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/21 18:03:59 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_numbers(t_all *all)
{
	t_stack *list;

	list = all->stack_a;
	if (is_sorted(list) == 0)
    	return;
	if (list->data > list->next->data)
	{
		if (list->next->data < list->next->next->data)
		{
			if (list->data < list->next->next->data)
				exec_instructions(all, "sa");
			else if (list->data > list->next->next->data)
				exec_instructions(all, "ra");
		}
		else
		{
			exec_instructions(all, "sa");
			exec_instructions(all, "rra");
		}
	}
	else
	{
		if (list->data < list->next->next->data)
		{
			exec_instructions(all, "sa");
			exec_instructions(all, "ra");
		}
		else
			exec_instructions(all, "rra");
	}
}

void	sort_5_numbers(t_all *all)
{
	t_stack *list_b;

	// five_numbers(all);
	// four_numbers(all);
	push_min_to_b(all);
	push_min_to_b(all);
	sort_3_numbers(all);
	list_b = all->stack_b;
	if (list_b->data < list_b->next->data)
	{
		exec_instructions(all, "sb");
	}
	exec_instructions(all, "pa");
	exec_instructions(all, "pa");

}

void	sort_function(t_all *all)
{
	t_stack *list;

	list = all->stack_a;
	while (list->next != NULL)
	{
		// exec_instructions(all, "pb");
		list = list->next;
	}
	printf("===========\n");
	display_list(all->stack_b);
	printf("===========\n");
}