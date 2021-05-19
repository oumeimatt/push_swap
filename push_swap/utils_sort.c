/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:36:16 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/19 16:56:44 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int 	smallest_element(t_stack *list)
{
	int		min;
	
	min = list->data;
	while(list != NULL)
	{
		if (min > list->data)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int    find_min_position(t_stack *stack)
{
    int i;
    int min;

    min = smallest_element(stack);
    i = 1;
    while (stack != NULL)
    {
        if (stack->data == min)
        {
            printf("data min == %d\n", stack->data);
            return (i);
        }
        i++;
        stack = stack->next;
    }
    return (0);
    
}

void    five_numbers(t_all *all)
{
    t_stack *list_a;
    int		pos;

	list_a = all->stack_a;
	pos = find_min_position(list_a);
    if (pos == 1)
		exec_instructions(all, "pb");
	if (pos == 2)
	{
		exec_instructions(all, "sa");
		exec_instructions(all, "pb");
	}
	if (pos == 3)
	{
		exec_instructions(all, "ra");
		exec_instructions(all, "ra");
		exec_instructions(all, "pb");
	}
	if (pos == 4)
	{
		exec_instructions(all, "rra");
		exec_instructions(all, "rra");
		exec_instructions(all, "pb");
	}
	if (pos == 5)
	{
		exec_instructions(all, "rra");
		exec_instructions(all, "pb");
	}
}

void    four_numbers(t_all *all)
{
    t_stack *list_a;
    int		pos;

	list_a = all->stack_a;
	pos = find_min_position(list_a);
    if (pos == 1)
		exec_instructions(all, "pb");
	if (pos == 2)
	{
		exec_instructions(all, "sa");
		exec_instructions(all, "pb");
	}
	if (pos == 3)
	{
		exec_instructions(all, "ra");
		exec_instructions(all, "ra");
		exec_instructions(all, "pb");
	}
	if (pos == 4)
	{
		exec_instructions(all, "rra");
		exec_instructions(all, "pb");
	}
}