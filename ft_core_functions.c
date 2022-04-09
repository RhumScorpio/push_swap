/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:58:29 by clesaffr          #+#    #+#             */
/*   Updated: 2022/04/03 16:44:00 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*malloc_the_node(void)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
	{
		printf("Error in memory allocation.\n");
		return (NULL);
	}
	return (new);
}

void	pre_indexing(t_node *a)
{
	t_node	*tmp;
	t_node	*compare;

	tmp = a;
	compare = a;
	while (tmp->next)
	{
		while (compare->next)
		{
			if (tmp->number > compare->number)
				tmp->index_sorted++;
			compare = compare->next;
		}
		compare = a;
		printf("INDEX >> %d [%d]\n", tmp->number, tmp->index_sorted);
		tmp = tmp->next;
	}
}

void	core_process(t_node *a, t_node *b)
{
	(void)b;
	pre_indexing(a);
}
