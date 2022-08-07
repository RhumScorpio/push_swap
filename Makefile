# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 21:04:05 by clesaffr          #+#    #+#              #
#    Updated: 2022/08/01 23:47:07 by clesaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

LIBFT		=	libft.a

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	ft_whitespaces_parsing.c \
				ft_pushargs_safely.c \
				ft_node_malloc_and_free.c\
				ft_core_functions.c \
				ft_sorting_by_bits_in_two_stacks.c \
				ft_sorting_for_stacksize_five.c \
				ft_sorting_for_stacksize_three.c \
				ft_stack_general_manipulation.c \
				ft_operating_on_list_b.c \
				ft_operating_on_list_a.c \
				ft_sorting_reverse.c \
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
