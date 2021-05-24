/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 18:42:46 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/23 19:06:02 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	help_sort_3(t_all *all, t_stack *list)
{
	if (list->data < list->next->next->data)
	{
		exec_instructions(all, "sa");
		exec_instructions(all, "ra");
	}
	else
		exec_instructions(all, "rra");
}

void	sort_3_numbers(t_all *all)
{
	t_stack	*list;

	list = all->stack_a;
	if (is_sorted(list) == 0)
		return ;
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
		help_sort_3(all, list);
}
