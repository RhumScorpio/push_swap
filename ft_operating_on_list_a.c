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

void	pa(t_node **b, t_node **a)
{
	t_node	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = b[0]->next;
	tmp->next = *a;
	*a = tmp;
	ft_putstr("pa\n");
}

void	sa(t_node **a)
{
	t_node	*tmp;

	if(!*a)
		return ;
	tmp = *a;
	*a = a[0]->next;
	tmp->next = a[0]->next;
	a[0]->next = tmp;
	ft_putstr("sa\n");
}

void	ra(t_node **a)
{
	t_node	*temp_a;
	t_node	*temp_next;

	if(!*a || list_too_short(a))
		return ;
	temp_a = *a;
	temp_next = temp_a;
	temp_a = temp_a->next;
	list_addback(temp_a, temp_next);
	*a = temp_a;
	ft_putstr("ra\n");
}

void    rra(t_node **a)
{
    t_node  *temp_a;
    t_node  *temp_prev;

    temp_a = *a;
    while (temp_a->next)
    {
        temp_prev = temp_a;
        temp_a = temp_a->next;
    }
    *a = link_new_node_to_head(*a, temp_a);
    temp_prev->next = NULL;
    ft_putstr("rra\n");
}

