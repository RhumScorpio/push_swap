/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:36:19 by clesaffr          #+#    #+#             */
/*   Updated: 2022/05/08 18:36:32 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_addback(t_node *list, t_node *add)
{
	while (list->next != NULL)
		list = list->next;
	list->next = add;
	add->next = NULL;
}

t_node  *link_new_node_to_head(t_node *list, t_node *node)
{
    t_node  *tmp;

    tmp = node;
    tmp->next = list;
    return (tmp);
}

int		get_list_size(t_node **list)
{
	t_node	*tmp;
	int		i;


	tmp = *list;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		list_too_short(t_node **list)
{
	if (get_list_size(list) < 2)
		return (1);
	return (0);
}