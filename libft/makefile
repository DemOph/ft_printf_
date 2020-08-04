# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/03 21:06:11 by chael-ha          #+#    #+#              #
#    Updated: 2020/06/19 10:19:16 by chael-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_isprint.c\
		ft_memset.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_putchar_fd.c\
		ft_strlcat.c\
		ft_substr.c\
		ft_bzero.c\
		ft_putendl_fd.c\
		ft_strlcpy.c\
		ft_tolower.c\
		ft_calloc.c\
		ft_memccpy.c\
		ft_putnbr_fd.c\
		ft_strlen.c\
		ft_toupper.c\
		ft_isalnum.c\
		ft_memchr.c\
		ft_putstr_fd.c\
		ft_strmapi.c\
		ft_isalpha.c\
		ft_memcmp.c\
		ft_split.c\
		ft_strncmp.c\
		ft_isascii.c\
		ft_memcpy.c\
		ft_strchr.c\
		ft_strnstr.c\
		ft_isdigit.c\
		ft_memmove.c\
		ft_strdup.c\
		ft_strrchr.c\
		ft_putstr.c\

SRC2 =	ft_lstmap_bonus.c\
		ft_lstnew_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstsize_bonus.c\

OBJ   = $(SRC:.c=.o)
OBJ2   = $(SRC2:.c=.o)
INCLUDES = libft.h
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus : $(OBJ2) $(INCLUDES)
	ar rc $(NAME) $(OBJ2)
	ranlib $(NAME)

$(OBJ) : %.o : %.c
	gcc $(FLAGS) -c $< -o $@
$(OBJ2) : %.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(OBJ2)

fclean : clean
	rm -rf $(NAME)

re : fclean all bonus
