# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 12:45:46 by oel-yous          #+#    #+#              #
#    Updated: 2021/05/24 16:41:40 by oel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c\
		utils_sort.c\
		utils_sort2.c\
		utils.c\
		utils2.c\
		leacks_cheker_ex.c\
		operations.c\
		apply_commands.c\
		sort.c\
		init.c\
		push_min_or_max.c\
		push_swap_free.c\
		fill_stack.c\
		

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(OBJS):$(SRCS)
		$(CC) -c $(SRCS)

$(NAME): $(OBJS)
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
		rm -rf $(OBJS)

fclean:clean
		rm -rf $(NAME)

re: fclean all