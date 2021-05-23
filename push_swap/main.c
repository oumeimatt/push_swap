/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:43:29 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/23 13:13:18 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_list(t_stack *head)
{
	t_stack *current = head;
    while (current != NULL)
    {
        printf("%d\n" , current->data);
        current = current->next;
    }
}

int     is_sorted(t_stack *head)
{
    t_stack *list;

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


int main(int argc, char **argv)
{
    int i;
	t_all *all;

	i = 1;
	if (argc == 1)
		exit (0);
	else
	{
		while (i < argc)
		{
			ft_atoi(argv[i]);
			i++;
		}
	}
	all = init_all(all);
	store_data(argc, argv, all);
	check_for_dup(all->stack_a);
    // if (argc == 4)
    //     sort_3_numbers(all);
    // if (argc == 6)
    //     sort_5_numbers(all);
    // if (argc > 6)
        sort_function(all); 
    if (is_sorted(all->stack_a) == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    // printf("---------\n");
    // display_list(all->stack_a);
    // printf("---------\n");
    // printf("==========\n");
    // display_list(all->stack_b);
    // printf("==========\n");
}



// python3 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
// ruby -e "puts (-250..250).to_a.shuffle.join(' ')"