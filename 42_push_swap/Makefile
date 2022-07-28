# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 13:36:47 by bkwag             #+#    #+#              #
#    Updated: 2021/05/28 13:47:219 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

DIR_HEADERS =	./includes/

DIR_SRCS	=	./srcs

LIBFT	=	libft.a

LIBS	=	-L./Libft -lft

SRCS	= 	main.c \
				srcs/ft_malloc.c srcs/operations.c srcs/push_swap.c srcs/under_five.c \
				srcs/utils.c srcs/utils2.c srcs/utils3.c srcs/utils4.c srcs/utils5.c \
				srcs/pivots.c srcs/under_five_utils.c \

CFLAG	= 	-Wall -Wextra -Werror
RM		=	rm -rf
OBJS	= $(SRCS:%.c=%.o)
DEBUG	=	-g -fsanitize=address

all		:	$(NAME)

$(LIBFT):
	@$(MAKE) -C ./Libft

$(NAME)	:	$(OBJS) $(LIBFT)
	@gcc $(CFLAG) -g $(LIBS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME) > /dev/null

clean	:
	@$(MAKE) -C ./Libft clean
	@rm -rf *.o
	@rm -rf $(OBJS)

fclean	: clean
	@$(MAKE) -C ./Libft fclean
	@rm -rf $(NAME)

re		: fclean all

.PHONY:			all, clean, fclean, re
