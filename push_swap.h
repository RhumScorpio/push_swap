/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 09:25:11 by clesaffr          #+#    #+#             */
/*   Updated: 2021/11/28 09:35:30 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef	struct	s_sort
{
	int				number;
	struct s_sort	*next;
	int				is_pivot;
	int				by_pivot;
	int				is_sorted;
}	t_sort;

typedef struct	s_stack
{
	t_sort	*top;
}	t_stack;

#endif
