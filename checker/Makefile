# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oumeima <oumeima@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 13:08:32 by oel-yous          #+#    #+#              #
#    Updated: 2021/04/18 22:15:05 by oumeima          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = checker.c utils.c get_next_line.c get_next_line_utils.c operations.c

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