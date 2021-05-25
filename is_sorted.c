/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:29:31 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/24 19:07:16 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sorted(t_stack *head)
{
	t_stack	*list;

	if (head == NULL)
		return (TRUE);
	list = head;
	while (list->next != NULL)
	{
		if (list->data > list->next->data)
			return (FALSE);
		list = list->next;
	}
	return (TRUE);
}

void	ft_add_nod_a(t_stack **list, int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	node->data = val;
	node->next = *list;
	*list = node;
}