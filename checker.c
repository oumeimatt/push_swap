/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:03 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/25 14:43:39 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	display_list(t_stack *head)
{
	t_stack *current = head;
    while (current != NULL)
    {
        printf("%d\n" , current->data);
        current = current->next;
    }
}

int	main(int argc, char **argv)
{
	int		i;
	t_all	*all;

	all = NULL;
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
	read_operations(all);
	printf("--------\n");
	display_list(all->stack_a);
	printf("--------\n");
	printf("=========\n");
	display_list(all->stack_b);
	printf("==========\n");
	free_all(all);
	return (0);
}
