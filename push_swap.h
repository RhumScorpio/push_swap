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
	int				index_sorted;
	struct s_node	*next;
}								t_node;

void    bitshifting(t_node **a, t_node **b);
t_node		*malloc_the_node(void);
void		node_push(t_node **s, int d);
int		get_list_size(t_node **list);
void	list_addback(t_node *list, t_node *add);
int		list_too_short(t_node **list);
void    rrb(t_node **b);
void	rb(t_node **b);
void	sb(t_node **b);
void	pb(t_node **a, t_node **b);
void    rra(t_node **a);
void	ra(t_node **a);
void	sa(t_node **a);
void	pa(t_node **b, t_node **a);
t_node  *link_new_node_to_head(t_node *list, t_node *node);

long long	ft_char_to_integer(const char *str);
void		show_stack(t_node *a);
void		core_process(t_node **a, t_node **b);
void		node_init(t_node *s);
void		node_free(t_node *s);
int			node_is_empty(t_node **s);
void		debug(t_node *a, char c);
int			while_digit(char *s);
int			push_args_safely(t_node **a, int ac, char **av);
void		debug_stack(t_node *a, t_node *b);

#endif
