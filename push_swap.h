/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:25:11 by clesaffr          #+#    #+#             */
/*   Updated: 2022/03/07 23:29:38 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_sort
{
	int				number;
	struct s_sort	*next;
	int				is_pivot;
	int				by_pivot;
	int				is_sorted;
}								t_sort;

typedef struct	s_stack
{
	t_sort	*top;
}							t_stack;

void	stack_init(t_stack *s);
void	stack_free(t_stack *s);
t_node	*stack_pop(t_stack *s);
void	stack_push(t_stack	*s, int d);
int	push_args_safely(t_stack *a, int ac, char **av);

int		stack_peek_data(t_stack *s);
int		stack_set_top_pivot(t_stack *s);
int		stack_is_node_pivot(t_node *n);
int		stack_is_top_pivot(t_stack *s);
int		stack_0_nodes_till_bottom_or_pivot(t_stack *s);

int		ft_strlen(char *s);
void	ft_putstr(char *s);
int		ft_atoi(const char *str);

#endif
