/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:55:40 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/23 19:07:23 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void	push_to_other_stack(t_stack **from, t_stack **to)
{
	t_stack	*save;

	if (!(*from))
		return ;
	save = *from;
	ft_add_node(to, save->data);
	delete_node(from);
}

void	ft_add_node(t_stack **list, int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (list && node)
	{
		node->data = val;
		node->next = *list;
		*list = node;
	}
}

void	delete_node(t_stack **head_ref)
{
	t_stack	*temp;

	if (head_ref == NULL || *head_ref == NULL)
		return ;
	temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
	return ;
}

void	swap_list(t_stack **head)
{
	t_stack	*list;
	int		temp;

	list = *head;
	if (list != NULL && list->next == NULL)
		return ;
	else if (list != NULL && list->next != NULL)
	{
		temp = list->data;
		list->data = list->next->data;
		list->next->data = temp;
	}
}

void	rotate_list(t_stack **head_ref, int k)
{
	t_stack	*current;
	t_stack	*kth_node;
	int		count;

	current = *head_ref;
	count = 1;
	while (count < k && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current == NULL)
		return ;
	kth_node = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head_ref;
	*head_ref = kth_node->next;
	kth_node->next = NULL;
}
