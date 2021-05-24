/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:08:54 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/24 19:06:54 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	valid_instructions_1(char *line)
{
	if (line[0] == 's')
	{
		if (ft_strncmp(line, "sa\0", 3) != 0 && ft_strncmp(line, "sb\0", 3) != 0
			&& ft_strncmp(line, "ss\0", 3) != 0)
			return (FALSE);
	}
	if (line[0] == 'r')
	{
		if (ft_strncmp(line, "ra\0", 3) != 0 && ft_strncmp(line, "rb\0", 3) != 0
			&& ft_strncmp(line, "rr\0", 3) != 0)
			return (FALSE);
	}
	if (line[0] == 'p')
	{
		if (ft_strncmp(line, "pa\0", 3) != 0 && ft_strncmp(line, "pb\0", 3) != 0)
			return (FALSE);
	}
	return (TRUE);
}

int	valid_instructions_2(char *line)
{
	if (line[0] == 'r' && line[1] == 'r')
	{
		if (line[2] != 'r' && line[2] != 'a' && line[2] != 'b')
			return (FALSE);
		return (TRUE);
	}
	else
		return (FALSE);
}

void	incorrect_instruc(char *line)
{
	int	len;

	len = ft_strlen(line);
	if ((len == 2 && valid_instructions_1(line))
		|| (len == 3 && valid_instructions_2(line)))
		ft_error();
	if (len < 2 || len > 3
		|| (line[0] != 'r' && line[0] != 's' && line[0] != 'p'))
		ft_error();
}

void	read_operations(t_all *all)
{
	int		ret;
	char	*line;
	t_stack	*list;

	while (get_next_line(0, &line) > 0)
	{
		incorrect_instruc(line);
		exec_instructions_check(all, line);
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
	if (is_sorted(all->stack_a) == TRUE && all->stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
