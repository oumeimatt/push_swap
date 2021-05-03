/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:33:39 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/03 15:27:10 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_all(t_stack *stack)
{
    if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
        ft_error();
    stack->stack_a = NULL;
    stack->stack_b = NULL;
    stack->line = NULL;
    stack->str = NULL;
    stack->stack_size = 0;
}