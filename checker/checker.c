/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:03 by oel-yous          #+#    #+#             */
/*   Updated: 2021/04/17 14:58:32 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		valid_instructions_1(char *line)
{
	if (line[0] == 's')
	{
		if (ft_strncmp(line, "sa\0", 3) != 0 && ft_strncmp(line, "sb\0", 3) != 0
		&& ft_strncmp(line, "ss\0", 3) != 0)
			return (1);
	}
	if (line[0] == 'r')
	{
		if (ft_strncmp(line, "ra\0", 3) != 0 && ft_strncmp(line, "rb\0", 3) != 0
		&& ft_strncmp(line, "rr\0", 3) != 0)
			return (1);
	}
	if (line[0] == 'p')
	{
		if (ft_strncmp(line, "pa\0", 3) != 0 && ft_strncmp(line, "pb\0", 3) != 0)
			return (1);
	}
	return (0);
}

int		valid_instructions_2(char *line)
{
	if (line[0] == 'r' && line[1] == 'r')
	{
		if (line[2] != 'r' && line[2] != 'a' && line[2] != 'b')
			return (1);
		return (0);
	}
	else
		return (1);
}

void	ft_error()
{
	write(1, "Error\n", 6);
	exit (0);
}

void	incorrect_instruc(char *line)
{
	int	len;
	
	len = ft_strlen(line);
	if ((len == 2 && valid_instructions_1(line) == 1) || 
	(len == 3 && valid_instructions_2(line) == 1))
		ft_error();	
	if (len < 2 || len > 3 ||
	 (line[0] != 'r' && line[0] != 's' && line[0] != 'p'))
		ft_error();
}

void	read_operations()
{
	int ret;
	char *line;

	while ((ret = get_next_line(0, &line))> 0)
	{
		incorrect_instruc(line);
	}
}

void store_data(int argc, char **argv, t_args **head)
{
	int i;

	i = 1;
	while (i < argc)
	{
	    t_args* args = (t_args*) malloc(sizeof(t_args));
    	args->data = argv[i];
    	args->next = (*head);
    	(*head) = args;
		i++;
	}
}

void	check_for_dup(t_args *temp)
{
	t_args *temp1;
	t_args *temp2;

	temp1 = temp;
	while (temp1 != NULL && temp1->next != NULL)
	{
		temp2 = temp1;
		while (temp2->next != NULL)
		{
			if (ft_strcmp(temp1->data, temp2->next->data) == 0)
				ft_error();
			else
				temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}	
}

void display_list(t_args *args)
{
    while (args!=NULL)
    {
        printf("%s\n" , args->data);
        args = args->next;
    }
}

int main(int argc, char **argv)
{
	int i;
	t_args *head;

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
	store_data(argc, argv, &head);
	check_for_dup(head);
	display_list(head);
	read_operations();
}

