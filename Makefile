# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 21:04:05 by clesaffr          #+#    #+#              #
#    Updated: 2022/04/17 20:03:23 by clesaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

LIBFT		=	libft.a

CC			=	cc

CFLAGS		=	-g3 -Wall -Werror -Wextra

SRCS		=	ft_pushargs_safely.c \
				ft_show_and_test.c \
				ft_stack_functions.c \
				ft_core_functions.c \
				ft_whitespaces_parsing.c \
				ft_stack_functions2.c \
				ft_operating_on_lists.c \
				main.c

OBJS		=	$(SRCS:.c=.o)

PATH_OBJS	=	.objs/

PATH_LIBFT	=	libft/

F_OBJS		=	$(addprefix $(PATH_OBJS), $(OBJS))

all			: $(PATH_OBJS) $(LIBFT) $(NAME)
	
$(PATH_OBJS):
				@mkdir -p $(PATH_OBJS)

$(NAME)		: $(F_OBJS)
				$(CC) $(F_OBJS) -o $(NAME) $(LIBFT)

$(LIBFT)	:
				make -C $(PATH_LIBFT)

$(PATH_OBJS)%.o	: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean			:
					@rm -rf $(F_OBJS) $(PATH_OBJS) $(LIBFT)

fclean			:	clean
					@rm -f $(NAME)
					@make fclean -C $(PATH_LIBFT)

re				:	fclean all

.PHONY: all clean fclean re
