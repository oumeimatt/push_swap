/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:59:25 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/03 16:56:55 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    swap_oper(t_stack **head)
{
	t_stack *list;
	int    temp;

	list = *head;
	if (list != NULL && list->next == NULL)
		return ;
	else if (list != NULL && list->next != NULL)
	{
		temp = list->data;
		list->data = list->next->data;
		list->next->data = temp;
	}
		//    write(1, "----\n", 6);
}

void    swap_function(t_all *all, char *line)
{
	t_stack *list_a;
	t_stack *list_b;

	list_a = all->stack_a;
	list_b = all->stack_b;
    if (line[1] == 'a')
    {
        swap_oper(&list_a);
        display_list(list_a);
    }
    if (line[1] == 'b')
        swap_oper(&list_b);
    if (line[1] == 's')
    {
        swap_oper(&list_a);
        swap_oper(&list_b);
    }
}

void    rotate_function(t_all *all, char *line)
{
	t_stack *list_a;
	t_stack *list_b;

	list_a = all->stack_a;
	list_b = all->stack_b;
    if (line[1] == 'a')
    {
        rotate_list(&list_a, 1);
        // display_list(list_a);
    }
    if (line[1] == 'b')
        rotate_list(&list_b, 1);
    if (line[1] == 'r')
    {
        rotate_list(&list_a, 1);
        rotate_list(&list_b, 1);
    }
}

void    rev_rotate_function(t_all *all, char *line, int argc)
{
	t_stack *list_a;
	t_stack *list_b;

	list_a = all->stack_a;
	list_b = all->stack_b;
    if (line[1] == 'a')
    {
        rotate_list(&list_a, argc - 2);
        // display_list(list_a);
    }
    if (line[1] == 'b')
        rotate_list(&list_b, argc - 2);
    if (line[1] == 'r')
    {
        rotate_list(&list_a, argc - 2);
        rotate_list(&list_b, argc - 2);
    }
}
// t_stack    *exec_instructions(t_all *all, char *line, int argc)
void	exec_instructions(t_all *all, char *line, int argc)
{
	// t_stack *list_a;
	// t_stack *list_b;

	// list_a = all->stack_a;
	// list_b = all->stack_b;
	if (line[0] == 'r' && ft_strlen(line) == 2)
		rotate_function(all, line);	
	if (line[0] == 's')
		swap_function(all, line);
	if (line[0] == 'r' && ft_strlen(line) == 3)
		rev_rotate_function(all, line, argc);
	if (line[0] == 'p')
	{
		if (line[1] == 'b')
			push_to_other_stack(&all->stack_a, &all->stack_b);
		else
			push_to_other_stack(&all->stack_b, &all->stack_a);

	}
}
void    rotate_list(t_stack **head_ref, int k)
{
	t_stack *current;
	t_stack *kth_node;
	int count;
	
	if (k == 0)
		return;
	current = *head_ref;
	count = 1;
	while (count < k && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current == NULL)
		return;
	kth_node = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head_ref;
	*head_ref = kth_node->next;
	kth_node->next = NULL;
}

void	push_to_other_stack(t_stack **from, t_stack **to)
{
	t_stack *save;
	t_stack *stock;

	if (!(*from))
		return;
	save = *from;
	ft_add_node(to, save->data);
	delete_node(from);
}


void ft_add_node(t_stack **list, int val)
{
    t_stack *node;
    
    if (list && (node = malloc(sizeof(t_stack))))
    {
		node->data = val;
		node->next = *list;
		*list = node;
	}
}
void    delete_node(t_stack **head_ref)
{
	t_stack  *temp;

	if (head_ref == NULL || *head_ref == NULL) 
		return;
	temp = *head_ref;
	*head_ref = temp->next;
	free(temp);
	return;
}