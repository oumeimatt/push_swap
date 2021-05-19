/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:51:07 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/19 16:55:27 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_numbers(t_all *all, char c)
{
	t_stack *list;
	if (c == 'a')
		list = all->stack_a;
	if (c == 'b')
		list = all->stack_b;
	if (list->data > list->next->data)
	{
		if (list->next->data < list->next->next->data)
		{
			if (list->data < list->next->next->data)
				exec_instructions(all, "sa");
			if (list->data > list->next->next->data)
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

	five_numbers(all);
	four_numbers(all);
	sort_3_numbers(all, 'a');
	list_b = all->stack_b;
	printf("list->data %d\n", list_b->data);
	printf("list->next->data %d\n", list_b->next->data);
	if (list_b->data < list_b->next->data)
	{
		printf("list->data %d\n", list_b->data);
		printf("list->next->data %d\n", list_b->next->data);
		exec_instructions(all, "sb");
	}
	exec_instructions(all, "pa");
	exec_instructions(all, "pa");

}
