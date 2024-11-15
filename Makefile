# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 23:01:14 by aelaaser          #+#    #+#              #
#    Updated: 2024/11/15 21:00:31 by aelaaser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = pipex.a

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = 	pipex.c utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

# Default target
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# Ensure libft is built first
$(LIBFT):
	make -C libft

# Rule to compile the object files from the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re