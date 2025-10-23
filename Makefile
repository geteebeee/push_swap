# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/24 23:25:13 by gorg              #+#    #+#              #
#    Updated: 2024/12/17 22:33:56 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2

###
LIBFT_DIR = ./Extras/libft
PRINTF_DIR = ./Extras/ft_print
SRCS_DIR = ./srcs/

###
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
FILES = functions.c lists.c main.c manual.c parsing.c parsing2.c radix.c

###
SRCS = $(addprefix $(SRCS_DIR),$(FILES))
OBJS = $(SRCS:.c=.o)

###
all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)
	
$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: fclean all

###

.PHONY: all clean fclean re
