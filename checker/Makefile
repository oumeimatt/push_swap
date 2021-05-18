# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 13:08:32 by oel-yous          #+#    #+#              #
#    Updated: 2021/05/18 09:12:02 by oel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = checker.c utils.c utils2.c get_next_line.c get_next_line_utils.c operations.c sort.c init.c push_swap_free.c fill_stack.c read_instructions.c

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