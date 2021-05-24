/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:00 by oel-yous          #+#    #+#             */
/*   Updated: 2021/05/24 16:30:43 by oel-yous         ###   ########.fr       */
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


//checker.c
void	ft_error();
void	check_for_dup(t_stack *head);
int		valid_instructions_1(char *line);
int		valid_instructions_2(char *line);
void	incorrect_instruc(char *line);
void	store_data(int argc, char **argv, t_all *all);
void	check_for_dup(t_stack *temp);
void	read_operations(t_all *all);
int 	main(int argc, char **argv);
void	display_list(t_stack *head);
int	count_list(t_stack *head);

//utils.c
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *str);
long	norme_atoi(char *str, int i, int signe);
void	fill_stack(t_stack *stack, int data);
void	ft_add_nod_a(t_stack **list, int val);
//operations.c
void    swap_list(t_stack **stack);
void    swap_function(t_all *all, char *line);
t_stack    *rotate_function(t_all *all, char c);
t_stack    *rev_rotate_function(t_all *all, char c);
void	exec_instructions(t_all *all, char *line);
void	remove_first(t_stack **head);
void	rotate_list(t_stack **head_ref, int k);
void	delete_node(t_stack **head_ref);
void    push_to_other_stack(t_stack **from, t_stack **to);
void	help_exec(t_all *all, char *line);
void ft_add_node(t_stack **list, int val);
// sort.c
int     is_sorted(t_stack *head);

//init.c
t_all    *init_all(t_all *all);

// get_next_line

char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
// push_swap_free.c
void		free_stack(t_stack *head);
void		free_all(t_all *all);
void	ft_error2(t_all *all);
void	help_help(t_all *all, char *line);
void	help_exec(t_all *all, char *line);


// PUSH_SWAP
void	sort_3_numbers(t_all *all);
int		main(int argc, char **argv);
void	sort_5_numbers(t_all *all);
t_stack    *swap(t_stack *a, t_stack *b);
int 	smallest_element(t_stack *list);
void    bubble_sort(t_stack **head);
int    find_value_position(t_stack *stack, int value);
int	even_or_odd(int n);
void	push_min_to_b(t_all *all, int value);
void	push_max_to_a(t_all *all, int value);
int		largest_element(t_stack *list);
void	sort_function(t_all *all);
void	sort_4_numbers(t_all *all);
void	sort_all(t_all *all, int argc);

void    apply_push(t_all *all, char *line);
void    apply_reverse(t_all *all, char *line);
void    apply_rotate(t_all *all, char *line);
void	help_sort_3(t_all *all, t_stack *list);
void	back_to_stack_a(t_all *all);
void    push_min_to_b_2(t_all *all, int value, int size, int pos);
void    push_max_to_a_2(t_all *all, int value, int size, int pos);

void check_leaks();
#endif