# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 11:10:44 by chael-ha          #+#    #+#              #
#    Updated: 2020/07/25 09:52:19 by chael-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = get_infos.c	\
	ft_printf.c \
	cout_digit.c \
	check_format.c \
	ft_print_char.c \
	ft_print_str.c \
	ft_print_s_basic.c \
	ft_print_width_minus_s.c \
	ft_print_prec_minus_s.c \
	ft_print_prec_non_minus_s.c \
	ft_Dec_to_Hex.c \
	ft_print_p.c \
	count_hex.c \
	ft_print_p_basic.c \
	ft_print_p_zero.c \
	ft_print_pourcent.c \
	ft_print_d.c \
	ft_print_u.c \
	ft_putnbr_u.c \
	
OBJ = $(SRC:.c=.o)

DEPS = ft_printf.h
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -Llibft
LDLIBS = -lft
CC = gcc
LIBFT = libft/libft.a
RM = rm -rf

all : $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft
	
$(NAME) : $(OBJ) $(DEPS)
		cp	libft/libft.a ./$(NAME)
		
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)


$(OBJ) : %.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft


fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all