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

//ft_whitespaces_parsing.c
int			is_str_int(char *s);
int			if_just_sign(char *s);
long long	ft_char_to_integer(const char *str);

//ft_pushargs_safely.c
int			ft_whitespace(char c);
int			push_args_safely(t_node **a, int ac, char **av);

//ft_node_malloc_and_free.c
t_node		*malloc_the_node(void);
void		node_free(t_node *s);
void		node_push(t_node **s, int d);

//ft_core_functions.c
void		core_process(t_node **a, t_node **b);
void		sort_stack_of_three(t_node **a);

//ft_sorting_by_bits_in_two_stacks.c
int			is_not_sorted(t_node **a);
void		bitshifting(t_node **a, t_node **b);

//ft_sorting_for_stacksize_five.c
void		sort_stack_of_five(t_node **a, t_node **b);

//ft_sorting_for_stacksize_three.c
void		sort_stack_of_three(t_node **a);

//ft_sorting_reverse.c
void		sort_stackb(t_node **b);

//ft_stack_general_manipulation.c
void		list_addback(t_node *list, t_node *add);
t_node		*link_new_node_to_head(t_node *list, t_node *node);
int			get_list_size(t_node **list);
int			list_too_short(t_node **list);

//ft_operating_on_list_b.c
void		pb(t_node **a, t_node **b);
void		sb(t_node **b);
void		rb(t_node **b);
void		rrb(t_node **b);

//ft_operating_on_list_a.c
void		pa(t_node **b, t_node **a);
void		sa(t_node **a);
void		ra(t_node **a);
void		rra(t_node **a);

#endif
