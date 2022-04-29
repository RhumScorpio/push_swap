/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:25:11 by clesaffr          #+#    #+#             */
/*   Updated: 2022/04/09 22:20:31 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				number;
	struct s_node	*next;
	int				is_pivot;
	int				by_pivot;
	int				index_sorted;
}								t_node;

t_node		*malloc_the_node(void);
void		node_push(t_node **s, int d);
int     if_node_is_last(t_node *s);
int     if_node_is_nexttolast(t_node *s);

long long	ft_char_to_integer(const char *str);
void		show_stack(t_node *a);
void		core_process(t_node **a, t_node **b);
void		node_init(t_node *s);
void		node_free(t_node *s);
int			node_is_empty(t_node *s);
void		debug(t_node **a, char c);
int			while_digit(char *s);
int			push_args_safely(t_node **a, int ac, char **av);
void		debug_stack(t_node **a, t_node **b);

#endif
