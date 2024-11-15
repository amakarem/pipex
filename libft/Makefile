# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 19:14:13 by aelaaser          #+#    #+#              #
#    Updated: 2024/10/16 22:52:49 by aelaaser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = 	ft_atoi.c ft_calloc.c ft_isalpha.c ft_isdigit.c ft_itoa.c ft_memcmp.c ft_memmove.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_strchr.c ft_strjoin.c ft_strlcpy.c ft_strncmp.c ft_strrchr.c ft_supstr.c ft_toupper.c ft_bzero.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memset.c ft_putnbr_fd.c ft_split.c ft_strdup.c ft_striteri.c ft_strlcat.c ft_strlen.c ft_strmapi.c ft_strnstr.c ft_strtrim.c ft_tolower.c

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

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
