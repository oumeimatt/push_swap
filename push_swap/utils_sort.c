/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:36:16 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/23 19:05:32 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	smallest_element(t_stack *list)
{
	int	min;

	min = list->data;
	while (list != NULL)
	{
		if (min > list->data)
			min = list->data;
		list = list->next;
	}
	return (min);
}

int	largest_element(t_stack *list)
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

int	find_value_position(t_stack *stack, int value)
{
	int	i;

	i = 1;
	while (stack != NULL)
	{
		if (stack->data == value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	even_or_odd(int n)
{
	if (n % 2 == 0)
		return (0);
	else
		return (1);
	return (0);
}
