/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:10:37 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/23 20:43:33 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fill_stack(t_all *all, int data)
{
	t_stack	**top;
	t_stack	*temp;

	top = &all->stack_a;
	if (*top)
	{
		temp = (t_stack *)malloc(sizeof(t_stack));
		if (!temp)
			// ft_error2(all);
			free_stack(temp);     
		temp->next = *top;
		(*top) = temp;
		temp->data = data;
		(*top)->next = NULL;
	}
	else
	{
		*top = (t_stack *)malloc(sizeof(t_stack));
		if (!(*top))
			// ft_error2(all);
			free_stack(*top);
		(*top)->next = NULL;
		(*top)->data = data;
	}
}

void	store_data(int argc, char **argv, t_all *all)
{
	int	i;
	int	data;

	i = argc - 1;
	while (i > 0)
	{
		data = ft_atoi(argv[i]);
		fill_stack(all, data);
		i--;
	}
}

void	check_for_dup(t_stack *temp)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = temp;
	while (temp1 != NULL && temp1->next != NULL)
	{
		temp2 = temp1;
		while (temp2->next != NULL)
		{
			if (temp1->data == temp2->next->data)
				ft_error();
			else
				temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}	
}
