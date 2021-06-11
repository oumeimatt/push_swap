/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:43:29 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/25 16:13:14 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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

	all = NULL;
	i = 0;
	if (argc == 1)
		exit (0);
	else
	{
		while (++i < argc)
			ft_atoi(argv[i]);
	}
	all = init_all(all);
	store_data(argc, argv, all);
	check_for_dup(all->stack_a);
	if (is_sorted(all->stack_a) == TRUE)
	{
		free_all(all);
		return (0);
	}
	sort_all(all, argc);
	free_all(all);
	return (0);
}
