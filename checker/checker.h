/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:00 by oel-yous          #+#    #+#             */
/*   Updated: 2021/04/17 14:58:39 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


typedef	struct	s_args
{
	char	*data;
	struct s_args* next;
}				t_args;

typedef struct	s_oper
{
	char	*instr;
	struct s_oper* next;
}				t_oper;

#define BUFFER_SIZE 100


//checker.c
void	ft_error();
void	check_for_dup(t_args *head);
int		valid_instructions_1(char *line);
int		valid_instructions_2(char *line);
void	incorrect_instruc(char *line);
void	store_data(int argc, char **argv, t_args **head);
void	check_for_dup(t_args *temp);
void	read_operations();
int 	main(int argc, char **argv);

//utils.c
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *str);

// get_next_line
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
#endif