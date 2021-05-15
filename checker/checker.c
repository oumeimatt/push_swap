/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:03 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/03 16:55:23 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		valid_instructions_1(char *line)
{
	if (line[1] == '\0')
		return(TRUE);
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

int		valid_instructions_2(char *line)
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
	if ((len == 2 && valid_instructions_1(line)) || 
	(len == 3 && valid_instructions_2(line)))
		ft_error();	
	if (len < 2 || len > 3 ||
	 (line[0] != 'r' && line[0] != 's' && line[0] != 'p'))
		ft_error();
}

void	read_operations(t_all *all)
{
	int ret;
	char *line;
	t_stack *list;

	while ((ret = get_next_line(0, &line))> 0)
	{
		if (line[0] == '\0')
			break;
		incorrect_instruc(line);
		exec_instructions(all, line);
		free(line);
	}
	free(line);
	printf("*****\n");
	display_list(all->stack_a);
	printf("*****\n");
	if (is_sorted(all->stack_a) == TRUE && all->stack_b == NULL)
	{
		free(all->stack_a);
		write(1,"OK\n", 3);
	}
	else
	{
		free(all->stack_a);
		free(all->stack_b);
		write(1, "KO\n", 3);
	}
}

void store_data(int argc, char **argv, t_all *all)
{
	int i;
	int data;

	i = argc - 1;
	while (i > 0)
	{
		data = ft_atoi(argv[i]);
		fill_stack(all, 'a', data);
		i--;
	}
}

void	check_for_dup(t_stack *temp)
{
	t_stack *temp1;
	t_stack *temp2;

	temp1 = temp;
	while (temp1 != NULL && temp1->next != NULL)
	{
		temp2 = temp1;
		while (temp2->next != NULL)
		{
			if (temp1->data == temp2->next->data)
				ft_error();
			else
				temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}	
}

void	display_list(t_stack *head)
{
	t_stack *current = head;
    while (current != NULL)
    {
        printf("%d\n" , current->data);
        current = current->next;
    }
}

int	count_list(t_stack *head)
{
	t_stack *current = head;
	int i = 0;
    while (current != NULL)
    {
		i++;
        current = current->next;
    }
	return (i);
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
	read_operations(all);
	free(all);

}

void	fill_stack(t_all *all, char s_name, int data)
{
	t_stack **top;
	t_stack *temp;

	if (s_name == 'a')
		top = &all->stack_a;
	else if (s_name == 'b')
		top = &all->stack_b;
	if (*top)
	{
		if (!(temp = (t_stack *)malloc(sizeof(t_stack))))
			ft_error2(all);
		temp->next = *top;
		(*top) = temp;
		temp->data = data;
	}
	else
	{
		if (!(*top = (t_stack *)malloc(sizeof(t_stack))))
			ft_error2(all);
		(*top)->next = NULL;
		(*top)->data = data;
	}
}