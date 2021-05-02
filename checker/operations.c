/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:59:25 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/02 14:55:54 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    swap_oper(t_args **head)
{
    t_args *list;
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

// void    swap_function(t_args **args, char *line)
// {
//     t_stack *stack;
//     // stack->stack_a = *args;
//     if (line[1] == 'a')
//     {
//         write(1, "2222\n", 5);  
//         swap_oper(&stack->stack_a);
//         display_list(stack->stack_a);
//     }
//     // if (line[1] == 'b')
//     //     swap_oper(&stack->stack_b);
//     // if (line[1] == 's')
//     // {
//     //     swap_oper(&stack->stack_a);
//     //     swap_oper(&stack->stack_b);
//     // }
// }
void    help_swap(t_args **head, char *line)
{
    t_args *list;
    t_stack *stack;
    list = *head;
    swap_oper(head);
    // if (line[1] == 'a')
    // {
    //     stack->stack_a = *head;
    //     // if (stack->stack_a == NULL)
    //     // {
    //     //     write(1, "4444\n", 5);
    //     //     return ;
    //     // }
    //     // printf("list == --> %s\n", list->data);
    //     // printf("list->next->data == --> %s\n", list->next->data);
    //     while (list->next != NULL)
    //     {
    //         list = (*head);
    //         // stack->stack_a->data = list->data;
    //         // printf("stack->stack_a->data == %s\n", stack->stack_a->data);
    //         (*head) = list->next;
            
    //     }
    // }
}

void    exec_instructions(t_args *args, char *line)
{
    if (line[0] == 's')
    {
        // write(1, "1111\n", 5);
        swap_oper(&args);
        // swap_function(&args, line);
    }
    if (line[0] == 'r')
    {
        rotate_list(&args, 1);
        display_list(args);
    }
       //swap_function "swap top two numbers";
//     if (line[0] == 'p')
//         // push_function "send top of * to top of *";
//     if (line[0] == 'r' && ft_strlen(line) == 2)
//         // rotate function "top goes to bottom"
//     if (line[0] == 'r' && ft_strlen(line) == 3)
//         // rotate_2_function "bottom goes to top"
}


void    rotate_list(t_args **head_ref, int k)
{
    t_args *current;
    t_args *kth_node;
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

void    push_to_other_stack(t_args *from, t_args *to)
{
    t_args *save;
    t_args *stock;

    if (!from)
        return;
    save = from;
    delete_node(&from, 0);
    if (!to)
    {
        to = save;
        to->next = NULL;
    }
    else
    {
        to = add_node(to, save->data);
    }
}

t_args *add_node(t_args *head, int data)
{
    t_args *node;
    node = (t_args*)malloc(sizeof(t_args));
    node->data = data;
    node->next = head;
    return (node);
}
void    delete_node(t_args **head_ref, int position)
{
    t_args  *temp;
    int i;
    t_args  *next;

   if (*head_ref == NULL)
      return;
   temp = *head_ref;
    if (position == 0)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    i = 0;
    while (temp != NULL && i < position - 1)
    {
         temp = temp->next;
         i++;
    }
    if (temp == NULL || temp->next == NULL)
         return;
    next = temp->next->next;
    free(temp->next);
    temp->next = next;
}
