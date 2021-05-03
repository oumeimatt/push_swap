/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:00 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/03 15:33:57 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

# define TRUE 0
# define FALSE 1
typedef	struct	s_args
{
	int	data;
	struct s_args* next;
}				t_args;

typedef struct	s_stack
{
	t_args	*stack_a;
	t_args	*stack_b;
	char	*line;
	char	*str;
	int		stack_size;
}				t_stack;

#define BUFFER_SIZE 1000


//checker.c
void	ft_error();
void	check_for_dup(t_args *head);
int		valid_instructions_1(char *line);
int		valid_instructions_2(char *line);
void	incorrect_instruc(char *line);
t_args	*store_data(int argc, char **argv, t_args **head);
void	check_for_dup(t_args *temp);
void	read_operations(t_args **args);
int 	main(int argc, char **argv);
void display_list(t_args *head);

//utils.c
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *str);
long	norme_atoi(char *str, int i, int signe);

//operations.c
void    swap_oper(t_args **args);
void    swap_function(t_args **args, char *line);
void    exec_instructions(t_args *args, char *line);
void	remove_first(t_args **head);
t_args *add_node(t_args *head, int data);
void    rotate_list(t_args **head_ref, int k);
void	delete_node(t_args **head_ref, int position);
void    push_to_other_stack(t_args *from, t_args *to);
// sort.c
int     is_sorted(t_args *head);

//init.c
void    init_all(t_stack *stack);

// get_next_line
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
#endif