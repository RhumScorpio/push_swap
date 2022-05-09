/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operating_on_list_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:41:22 by clesaffr          #+#    #+#             */
/*   Updated: 2022/05/09 16:41:29 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = a[0]->next;
	tmp->next = *b;
	*b = tmp;
	ft_putstr("pa\n");
}

void	sa(t_node **b)
{
	t_node	*tmp;

	if(!*b)
		return ;
	tmp = *b;
	*b = b[0]->next;
	tmp->next = b[0]->next;
	b[0]->next = tmp;
	ft_putstr("sa\n");
}

void	ra(t_node **b)
{
	t_node	*temp_b;
	t_node	*temp_next;

	if(!*b || list_too_short(b))
		return ;
	temp_b = *b;
	temp_next = temp_b;
	temp_b = temp_b->next;
	list_addback(temp_b, temp_next);
	*b = temp_b;
	ft_putstr("ra\n");
}

void    rra(t_node **b)
{
    t_node  *temp_b;
    t_node  *temp_prev;

    temp_b = *b;
    while (temp_b->next)
    {
        temp_prev = temp_b;
        temp_b = temp_b->next;
    }
    *b = link_new_node_to_head(b, temp_b);
    temp_prev->next = NULL;
    ft_putstr("rra\n");
}

