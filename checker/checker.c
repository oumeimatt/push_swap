/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:03 by oel-yous          #+#    #+#             */
/*   Updated: 2021/04/29 11:45:24 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		valid_instructions_1(char *line)
{
	if (line[1] == '\0')
		return(0);
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

void	read_operations(t_args **args)
{
	int ret;
	char *line;
	t_args *list;
	// t_stack *stack;
	

	list = *args;
	while ((ret = get_next_line(0, &line))> 0)
	{
		if (line[0] == '\0')
			break;
		incorrect_instruc(line);
		exec_instructions(list, line);

	}
	printf("----------------\n");
	display_list(list);
	if (is_sorted(list) == TRUE)
		write(1,"OK\n", 3);
	else
		write(1, "KO\n", 3);
}

t_args store_data(int argc, char **argv, t_args **head)
{
	int i;
	t_args* args;
	t_stack *stack;

	i = argc -1;
	while (i > 0)
	{
		args = (t_args*) malloc(sizeof(t_args));
		stack->stack_a = (t_args*)malloc(sizeof(t_args) * argc);
    	stack->stack_b = (t_args*)malloc(sizeof(t_args) * argc);
		// args = stack->stack_a;
		args->data = ft_atoi(argv[i]);
		// printf("args->data == %s\n", args->data);
		// printf("stack->stack_a->data == %s\n", stack->stack_a->data);
    	args->next = (*head);
    	(*head) = args;
		i--;
	}
	return (*stack->stack_a);
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
				ft_error();
			else
				temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}	
}

void display_list(t_args *head)
{
	t_args *current = head;

    while (current != NULL)
    {
        printf("%d\n" , current->data);
        current = current->next;
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
	read_operations(&head);
	printf ("----------\n");
	rotate_list(&head, argc - 2);
	display_list(head);
}