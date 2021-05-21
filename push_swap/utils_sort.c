/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:36:16 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/21 17:25:16 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int 	smallest_element(t_stack *list)
{
	int		min;
	
	min = list->data;
	while (list != NULL)
	{
		if (min > list->data)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int		largest_element(t_stack *list)
{
	int	max;

	max = list->data;
	while (list != NULL)
	{
		if (max < list->data)
			max = list->data;
		list = list->next;
	}
	return (max);
}

int    find_value_position(t_stack *stack, int value)
{
    int i;

    i = 1;
    while (stack != NULL)
    {
        if (stack->data <= value)
            return (i);
        i++;
        stack = stack->next;
    }
    return (0);
    
}

void	push_min_to_b(t_all *all)
{
	t_stack	*list_a;
	int	pos;
	int	size;
	int	min;

	list_a = all->stack_a;
	min = smallest_element(list_a);
	size = count_list(list_a);
	pos = find_value_position(list_a, min);
	if (pos <= 2)
	{
		if (pos > 1)
			exec_instructions(all, "sa");
		exec_instructions(all, "pb");
	}
	else
	{
		if ((even_or_odd(size) == 1 && pos <= (size / 2) + 1) || 
		(even_or_odd(size) == 0 && pos <= size / 2))
		{
			while (pos >= (size / 2))
			{
				exec_instructions(all, "ra");
				pos--;
			}
		}
		else if ((even_or_odd(size) == 1 && pos > (size / 2)) ||
		(even_or_odd(size) == 0 && pos > (size / 2)))
		{
			while (pos <= size)
			{
				exec_instructions(all, "rra");
				pos++;
			}
		}
		exec_instructions(all, "pb");
	}
	printf("+++++++\n");
	display_list(all->stack_b);
	printf("+++++++\n");
}