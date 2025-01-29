# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 10:38:28 by rheringe          #+#    #+#              #
#    Updated: 2024/11/01 16:03:33 by rheringe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

MANDATORY_SRC = ft_printf.c \
				ft_printf_utils.c \
				ft_printf_utils2.c

MANDATORY_OBJ = $(MANDATORY_SRC:%.c=%.o)

BONUS_SRC = ft_printf_bonus.c \
			ft_printf_utils_bonus.c \
			ft_printf_utils2_bonus.c \
			ft_printf_utils3_bonus.c
 
BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)

%.o: %.c ft_printf.h 
	$(CC) $(CFLAGS) -c $< -o $@
	ar rcs $(NAME) $@

bonus: $(BONUS_OBJ)

norm:
	norminette -R CheckForbiddenSourceHeader $(MANDATORY_SRC) $(BONUS_SRC) ft_printf.h ft_printf_bonus.h

clean: 
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re