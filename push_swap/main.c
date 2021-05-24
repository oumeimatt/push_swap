/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:43:29 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/24 16:56:13 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *head)
{
	t_stack	*list;

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

void	sort_all(t_all *all, int argc)
{
	if (argc == 4)
		sort_3_numbers(all);
	else if (argc == 5)
		sort_4_numbers(all);
	else if (argc == 6)
		sort_5_numbers(all);
	else
		sort_function(all);
}

int	main(int argc, char **argv)
{
	int		i;
	t_all	*all;

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
	sort_all(all, argc);
	display_list(all->stack_a);
	free_all(all);
	check_leaks();
	return (0);
}
