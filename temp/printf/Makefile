# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboutsli <yboutsli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 22:59:58 by yboutsli          #+#    #+#              #
#    Updated: 2023/11/27 21:39:56 by yboutsli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_file1.c ft_file2.c

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS_OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS_OBJ)
	ar -rc $(NAME) $(SRCS_OBJ)
%.o:%.c ft_printf.h
	cc $(CFLAGS) -c $< -o $@
clean : 
	rm -rf $(SRCS_OBJ)
fclean :
	rm -rf $(SRCS_OBJ) $(NAME)
re : fclean all