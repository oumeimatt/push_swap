/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:33:39 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/23 14:41:39 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_all    *init_all(t_all *all)
{
    if (!(all = (t_all *)malloc(sizeof(t_all))))
        exit(1);
    all->stack_a = NULL;
    all->stack_b = NULL;
    return(all);
}