# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 14:04:21 by clesaffr          #+#    #+#              #
#    Updated: 2022/03/08 00:12:15 by clesaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		=	push_swap

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	main.c/
				ft_pushing_args.c/
				ft_return_int.c/
				ft_stack_function.c/
				libft.c

HEADER		=	push_swap.h

OBJS		=	$(SRCS:.c=.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS)

$(OBJS)			:	$(SRCS)
					$(CC) $(FLAGS) -c $(SRCS) -o $(NAME)

clean			:
					@rm -rf $(OBJS)

fclean			:	clean
					@rm -f $(NAME)

re				:	fclean all

.PHONY: clean fclean all re
