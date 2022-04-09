/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:49:35 by clesaffr          #+#    #+#             */
/*   Updated: 2022/04/03 16:41:40 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	node_is_empty(t_node *s)
{
	return (s == NULL);
}

void	node_free(t_node *s)
{
	t_node	*top;

	while (!node_is_empty(s))
	{
		top = s;
		s = s->next;
		free(top);
	}
	free(s);
}

void	node_push(t_node **s, int d)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->number = d;
	tmp->next = NULL;
	tmp->is_pivot = 0;
	tmp->by_pivot = 0;
	tmp->index_sorted = 0;
	if (node_is_empty(*s))
		*s = tmp;
	else
	{
		tmp->next = *s;
		*s = tmp;
	}
}

