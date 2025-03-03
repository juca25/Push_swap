# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 14:54:18 by juan-ser          #+#    #+#              #
#    Updated: 2025/03/03 14:59:58 by juan-ser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)
NAME = push_swap.a
LIB = push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(LIB)
	$(CC) $(CFLAGS) -c $(SRCS)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re