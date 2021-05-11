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

// void    swap_function(t_all *all char *line)
// {
//     if (line[1] == 'a')
//     {
//         write(1, "2222\n", 5);  
//         swap_oper(&all->stack_a);
//         display_list(all->stack_a);
//     }
//     if (line[1] == 'b')
//         swap_oper(&all->stack_b);
//     if (line[1] == 's')
//     {
//         swap_oper(&all->stack_a);
//         swap_oper(&all->stack_b);
//     }
// }

t_stack    *exec_instructions(t_all *all, char *line, int argc)
{
	t_stack *list_a;
	t_stack *list_b;

	list_a = all->stack_a;
	list_b = all->stack_b;
	if (line[0] == 'r' && ft_strlen(line) == 2)
	{
		if (line[1] == 'a')
			rotate_list(&list_a, 1);
		if (line[1] == 'b')
			rotate_list(&list_b, 1);
		if (line[1] == 'r')
		{
			rotate_list(&list_a, 1);
			rotate_list(&list_b, 1);
		}
	}
	
	if (line[0] == 's')
	{
		if (line[1] == 'a')
	    	swap_oper(&list_a);
		if (line[1] == 'b')
			swap_oper(&list_b);
		if (line[1] == 's')
		{
			swap_oper(&list_a);
			swap_oper(&list_b);
		}
	}
	if (line[0] == 'r' && ft_strlen(line) == 3)
	{
		if (line[2] == 'a')
			rotate_list(&list_a,  argc - 2);
		if (line[2] == 'b')
			rotate_list(&list_b,  argc - 2);
		if (line[2] == 'r')
		{
			rotate_list(&list_a,  argc - 2);
			rotate_list(&list_b,  argc - 2);

		}
	}
	if (line[0] == 'p')
	{
		if (line[1] == 'b')
		{
			push_to_other_stack(&list_a, &list_b);
			delete_node(&list_a);
			printf(">>>>>>>>\n");
			display_list(list_a);
			printf(">>>>>>>>\n");
		}
		else
		{
			push_to_other_stack(&list_b, &list_a);
			delete_node(&list_b);
		}

	}
//     if (line[0] == 'p')
//         // push_function "send top of * to top of *";
	return (list_a);
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

void    push_to_other_stack(t_stack **from, t_stack **to)
{
	t_stack *save;
	t_stack *stock;

	if (!from)
		return;
	save = *from;
	if (*to)
	{
		write(1,"###\n", 4);
		(*to) = add_node(*to, save->data);
		display_list(*to);
	}
	if (!(*to))
	{
		// (*to) = add_node(*to, save->data);
		(*to) = save;
		(*to)->next = NULL;
		// printf("00000000000\n");
		// display_list(*to);
		// printf("00000000000\n");
	}
	printf("$$$$$$\n");
	display_list(*to);
	printf("$$$$$$\n");
	// delete_node(from, 0);
}

t_stack *add_node(t_stack *head, int data)
{
	t_stack *node;
	node = (t_stack*)malloc(sizeof(t_stack));
	node->data = data;
	node->next = head;
	return (node);
}
void    delete_node(t_stack **head_ref)
{
// 	t_stack  *temp;
// 	int i;
// 	t_stack  *next;

//    if (*head_ref == NULL)
// 	  return;
//    temp = *head_ref;
// 	if (position == 0)
// 	{
// 		*head_ref = temp->next;
// 		free(temp);
// 		return;
// 	}
// 	i = 0;
// 	while (temp != NULL && i < position - 1)
// 	{
// 		 temp = temp->next;
// 		 i++;
// 	}
// 	if (temp == NULL || temp->next == NULL)
// 		 return;
// 	next = temp->next->next;
// 	free(temp->next);
// 	temp->next = next;
//   t_stack *tmp;

//   /*Linked list does not exist or the list is empty*/
//   if(head_ref == NULL || *head_ref == NULL) return;
  
//   /*Storing the head to a temporary variable*/
//   tmp = *head_ref;
  
//   /*Moving head to the next node*/
//   *head_ref = (*head_ref)->next;
  
//   /*Deleting the first node*/
//   free(tmp);


}
