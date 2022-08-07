/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_malloc_and_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:39:13 by clesaffr          #+#    #+#             */
/*   Updated: 2022/07/29 16:39:28 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*malloc_the_node(void)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	node_free(t_node *s)
{
	t_node	*top;

	if (s == NULL)
		return ;
	while (s->next)
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
	if (!tmp)
		return ;
	tmp->number = d;
	tmp->next = NULL;
	tmp->index_sorted = 0;
	if (!*s)
		*s = tmp;
	else
	{
		tmp->next = *s;
		*s = tmp;
	}
}
