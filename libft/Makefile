# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 19:14:13 by aelaaser          #+#    #+#              #
#    Updated: 2024/10/17 18:22:53 by aelaaser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = 	ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_memcmp.c ft_memmove.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strchr.c ft_strjoin.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_substr.c ft_toupper.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memset.c ft_putnbr_fd.c ft_split.c ft_strdup.c ft_striteri.c ft_strlcat.c ft_strlen.c ft_strmapi.c ft_strnstr.c ft_strtrim.c ft_tolower.c

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

# Library name
NAME = libft.a

# Default target
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Clean up build files
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	 rm -f $(NAME)

re: fclean all

bonus:	$(OBJS) $(BONUS_OBJS)
			ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean bonus re
