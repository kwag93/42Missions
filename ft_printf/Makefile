# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkwag <bkwag@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/07 12:17:12 by hyunyoo           #+#    #+#              #
#    Updated: 2020/11/02 17:18:12 by bkwag            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a

AR = ar
ARFLAGS = rcs

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./includes -I./libft
LIB_FLAGS = -L./libft -lft -L. -lftprintf

RM = rm -f

FILES = ft_printf ft_printf_option ft_printf_character \
		ft_printf_number ft_printf_str ft_printf_unsigned_number ft_printf_hexa_number \
		ft_printf_pointer ft_printf_option2

SRC_DIR = ./srcs/
SRCS = $(addprefix ($SRC_DIR), $(addsuffix .c, $(FILES)))

OBJ_DIR = ./objs/
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJS)


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C ./libft all
	$(MAKE) -C ./libft bonus

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C ./libft fclean
	$(RM) -r a.out a.out.dSYM leaks_result

re: fclean all

.PHONY: all clean fclean re
