/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:33:29 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/24 16:36:21 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *head)
{
	t_stack	*tmp;

	while (head != NULL)
	{
		tmp = head;
		free(tmp);
		if (head->next != NULL)
			head = head->next;
		else
			break ;
	}
}

void	free_all(t_all *all)
{
	if (all)
	{
		if (all->stack_a)
			free_stack(all->stack_a);
		if (all->stack_b)
			free_stack(all->stack_b);
		free(all);
	}
}

void	ft_error2(t_all *all)
{
	free_all(all);
	write(1, "Error\n", 6);
	exit (0);
}

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit (0);
}
