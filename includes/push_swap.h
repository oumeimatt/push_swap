/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:00 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/24 19:09:48 by oel-yous         ###   ########.fr       */
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
typedef	struct	s_stack
{
	int	data;
	struct s_stack* next;
}				t_stack;

typedef struct	s_all
{
	t_stack	*stack_a;
	t_stack	*stack_b;
}				t_all;

# define BUFFER_SIZE 1000000


// checker
int	main(int argc, char **argv);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int	ft_finish(char **str, char **line);
int	ft_remplissage(char **str, char **line, int len);
int	ft_read(int fd, char **str);
int	get_next_line(int fd, char **line);
int	is_sorted(t_stack *head);
void	ft_add_nod_a(t_stack **list, int val);
void	swap_function_check(t_all *all, char *line);
t_stack	*rotate_function_check(t_all *all, char c);
t_stack	*rev_rotate_function_check(t_all *all, char c);
void	exec_instructions_check(t_all *all, char *line);
void	help_exec_check(t_all *all, char *line);
int	valid_instructions_1(char *line);
int	valid_instructions_2(char *line);
void	incorrect_instruc(char *line);
void	read_operations(t_all *all);


// push_swap
void	apply_rotate(t_all *all, char *line);
void	apply_reverse(t_all *all, char *line);
void	apply_push(t_all *all, char *line);
void	sort_all(t_all *all, int argc);
int	main(int argc, char **argv);
void	swap_function(t_all *all, char *line);
t_stack	*rotate_function(t_all *all, char c);
t_stack	*rev_rotate_function(t_all *all, char c);
void	exec_instructions(t_all *all, char *line);
void	push_min_to_b(t_all *all, int value);
void	push_min_to_b_2(t_all *all, int value, int size, int pos);
void	push_max_to_a(t_all *all, int value);
void	push_max_to_a_2(t_all *all, int value, int size, int pos);
void	sort_5_numbers(t_all *all);
void	sort_4_numbers(t_all *all);
void	sort_function(t_all *all);
void	back_to_stack_a(t_all *all);
int	smallest_element(t_stack *list);
int	largest_element(t_stack *list);
int	find_value_position(t_stack *stack, int value);
int	even_or_odd(int n);
void	help_sort_3(t_all *all, t_stack *list);
void	sort_3_numbers(t_all *all);

// shared

void	store_data(int argc, char **argv, t_all *all);
void	check_for_dup(t_stack *temp);
t_all	*init_all(t_all *all);
void	free_stack(t_stack *head);
void	free_all(t_all *all);
void	ft_error2(t_all *all);
void	ft_error(void);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(char *s1, char *s2);
int	ft_atoi(char *str);
long	norme_atoi(char *str, int i, int signe);
int	count_list(t_stack *head);
void	push_to_other_stack(t_stack **from, t_stack **to);
void	ft_add_node(t_stack **list, int val);
void	delete_node(t_stack **head_ref);
void	swap_list(t_stack **head);
void	rotate_list(t_stack **head_ref, int k);
int	is_sorted(t_stack *head);
void	ft_add_nod_a(t_stack **list, int val);

#endif