/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:03 by oel-yous          #+#    #+#             */
/*   Updated: 2021/04/16 17:29:44 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include <string.h>


int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if (s1[i] == '\0' || i >= (n - 1))
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}


int check_arg(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

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
	// int j;
	
	i = 1;
	// // j = 1;
	// head = NULL;
	// head = (t_args *)malloc(sizeof(t_args));
	// head->data = argv[1];
	// // stack_a[0] = head->data;
	// while (i < argc)
	// {
	// 	head->next = (t_args *)malloc(sizeof(t_args));
	// 	head->next->data = argv[i];
	// 	// stack_a[j] = head->next->data;
	// 	i++;
	// 	// j++;
	// }
	while (i < argc)
	{
	    t_args* new_node = (t_args*) malloc(sizeof(t_args));
    	new_node -> data = argv[i];
    	new_node -> next = (*head);
    	(*head) = new_node;
	}
	check_for_dup(*head);
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
			if (temp1->data == temp2->next->data)
			{
				write (1, "Error\n", 6);
				exit (0);
			}
			else
				temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	
}
int main(int argc, char **argv)
{
	int i;
	t_args *head;
	// char *stack_a;

	i = 1;
	if (argc == 1)
		exit (0);
	else
	{
		while (i >= 1 && i < argc)
		{
			if (check_arg(argv[i]) == 1)
			{
				write (1, "Error\n", 6);
				exit (0);
			}
			i++;
		}
	}
	store_data(argc, argv, &head);
	read_operations();
	
}

