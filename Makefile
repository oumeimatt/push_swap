# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 12:45:46 by oel-yous          #+#    #+#              #
#    Updated: 2021/05/25 14:43:11 by oel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

BONUS_NAME  = checker

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

SRCS		= main.c \
				utils_sort.c \
				utils_sort2.c \
				utils.c \
				utils2.c \
				operations_ps.c \
				apply_commands.c \
				sort.c \
				init.c \
				push_min_or_max.c \
				push_swap_free.c \
				fill_stack.c \
				is_sorted.c \
		
BONUS		= checker.c \
				get_next_line.c \
				get_next_line_utils.c \
				read_instructions.c \
				operations_checker.c \
				fill_stack.c \
				init.c \
				push_swap_free.c \
				is_sorted.c \
				utils.c \
				utils2.c \


OBJS 		= $(SRCS:.c=.o)

BONUS_OBJS 	= $(BONUS:.c=.o)

all: $(NAME)

$(NAME):$(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

#$(NAME): $(OBJS)
#		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

bonus:	$(BONUS_NAME)

$(BONUS_NAME): $(BONUS)
				$(CC) $(BONUS) $(CFLAGS) -o $(BONUS_NAME)

clean:
		rm -rf $(OBJS) $(BONUS_OBJS)

fclean:clean
		rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
