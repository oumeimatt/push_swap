/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:59:25 by oel-yous          #+#    #+#             */
/*   Updated: 2021/04/19 14:30:37 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    swap_oper(t_args **head ,char c)
{
    t_args *list;
    char *temp;

    list = *head;
    if (list != NULL && list->next == NULL)
        return ;
        
    else if (list != NULL && list->next != NULL)
    {
        temp = list->data;
        list->data = list->next->data;
        list->next->data = temp;
    }
    if (c == 's')
    {
        swap_oper(head, 'a');
        swap_oper(head, 'b');
    }
}

void    help_swap(t_args **head, char c)
{
    t_args *list;
    t_stack *stack;

    swap_oper(head, c);
    if (c == 'a')
    {
        if (stack->stack_a == NULL)
            return ;
        while (list->next != NULL)
        {
            list = (*head);
            stack->stack_a->data = list->data;
            printf("stack->stack_a->data == %s\n", stack->stack_a->data);
            (*head) = list->next;
            
        }
    }
}
  