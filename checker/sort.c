/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:29:31 by oel-yous          #+#    #+#             */
/*   Updated: 2021/04/27 13:05:08 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int     is_sorted(t_args *head)
{
    t_args *list;

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

