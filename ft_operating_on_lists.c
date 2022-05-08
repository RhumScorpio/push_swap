/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operating_on_lists.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:34:39 by clesaffr          #+#    #+#             */
/*   Updated: 2022/05/08 18:34:57 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = a[0]->next;
	tmp->next = *b;
	*b = tmp;
	ft_putstr("pb\n");
}

void	sb(t_node **b)
{
	t_node	*tmp;

	if(!*b)
		return ;
	tmp = *b;
	*b = b[0]->next;
	tmp->next = b[0]->next;
	b[0]->next = tmp;
	ft_putstr("sb\n");
}

void	rb(t_node **b)
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
	ft_putstr("rb\n");
}

t_node  *add_new_node_to_list(t_node **list, t_node *node)
{
    t_node  *tmp;

    tmp = node;
    tmp->next = *list;
    return (tmp);
}
void    rrb(t_node **b)
{
    t_node  *temp_b;
    t_node  *temp_prev;

    temp_b = *b;
    while (temp_b->next)
    {
        temp_prev = temp_b;
        temp_b = temp_b->next;
    }
    *b = add_new_node_to_list(b, temp_b);
    temp_prev->next = NULL;
    ft_putstr("rrb\n");
}