/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:59:25 by oel-yous          #+#    #+#             */
/*   Updated: 2021/04/27 13:09:53 by oel-yous         ###   ########.fr       */
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
        //swap_function "swap top two numbers";
//     if (line[0] == 'p')
//         // push_function "send top of * to top of *";
//     if (line[0] == 'r' && ft_strlen(line) == 2)
//         // rotate function "top goes to bottom"
//     if (line[0] == 'r' && ft_strlen(line) == 3)
//         // rotate_2_function "bottom goes to top"
}
  