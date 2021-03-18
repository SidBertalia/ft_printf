# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbertali <sbertali@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 16:18:08 by sbertali          #+#    #+#              #
#    Updated: 2021/03/18 12:36:04 by sbertali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 		ft_printf.c \
			ft_handle_char.c \
			ft_handle_flags.c \
			ft_handle_hex.c \
			ft_handle_int.c \
			ft_handle_percent.c \
			ft_handle_pointer.c \
			ft_handle_string.c \
			ft_handle_unsigned.c \
			ft_handle_width.c \
			ft_handle.c \
			ft_isdigit.c \
			ft_itoa.c \
			ft_unsigned_itoa.c \
			ft_putchar.c \
			ft_put_dot.c \
			ft_str_tolower.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_tolower.c \
			ft_utl_base.c

OBJECTS = 	ft_printf.o \
			ft_handle_char.o \
			ft_handle_flags.o \
			ft_handle_hex.o \
			ft_handle_int.o \
			ft_handle_percent.o \
			ft_handle_pointer.o \
			ft_handle_string.o \
			ft_handle_unsigned.o \
			ft_handle_width.o \
			ft_handle.o \
			ft_isdigit.o \
			ft_itoa.o \
			ft_unsigned_itoa.o \
			ft_putchar.o \
			ft_put_dot.o \
			ft_str_tolower.o \
			ft_strdup.o \
			ft_strlen.o \
			ft_tolower.o \
			ft_utl_base.o

INCLUDES = ft_printf.h


all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
