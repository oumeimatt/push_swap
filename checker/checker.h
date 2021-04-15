/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:05:00 by oel-yous          #+#    #+#             */
/*   Updated: 2021/04/15 12:11:46 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdlib.h>
#include <unistd.h>
#include "../libft/libft.h"



typedef	struct	s_data
{
	int	data;
	struct s_data* next;
}				t_data;

typedef struct	s_oper
{
	char	*op;
	struct s_oper* next;
}				t_oper;



#define BUFFER_SIZE 100
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);
#endif