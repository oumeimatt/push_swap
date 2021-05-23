/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:29:31 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/23 17:47:27 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
