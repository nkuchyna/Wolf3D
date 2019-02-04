# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkuchyna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/23 10:13:22 by nkuchyna          #+#    #+#              #
#    Updated: 2018/08/17 15:02:01 by nkuchyna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC  = ft_atoi.c ft_bzero.c ft_change_register.c ft_createarray_charx2.c\
		ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
		ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c\
		ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
		ft_printarray_charx2.c ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c\
		ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c\
		ft_reverse_str.c ft_sort_int_array.c ft_strcat.c ft_strchr.c\
		ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c\
		ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
		ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c\
		ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c\
		ft_tolower.c ft_toupper.c get_next_line.c ft_clear_str.c\
		ft_exit_x.c ft_free_char_array.c ft_strjoin_n.c ft_strsplit_new.c\
		ft_strstr_new.c


OBJ  = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror
INC  = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(INC)
		ar rc $(NAME) $(OBJ)

$(OBJ): %.o : %.c
		gcc $(FLAG) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re	: fclean all
