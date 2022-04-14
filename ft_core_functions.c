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

int	pre_indexing(t_node **a)
{
	t_node			*tmp;
	t_node			*compare;
	unsigned int	i;

	if (!a)
		return (0);
	i = 0;
	tmp = *a;
	compare = *a;
	while (tmp)
	{
		while (compare)
		{
			if (tmp->number > compare->number)
				tmp->index_sorted++;
			compare = compare->next;
		}
		compare = *a;
		printf("INDEX >> %d [%d]\n", tmp->number, tmp->index_sorted);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_node	*get_first_node(t_node **s)
{
	t_node	*tmp;
	t_node	*original;

	original = *s;
	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->number = original->number;
	tmp->index_sorted = original->index_sorted;
	tmp->next = NULL;
	return (tmp);
}

void	pb(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*tmp_free;

	if (!*a)
		return ;
	tmp = get_first_node(a);
	if (!*b)
		*b = tmp;
	else
	{
		tmp->next = *b;
		*b = tmp;
	}
	tmp_free = *a;
	*a = tmp_free->next;
	ft_putstr("pb\n");
}


void	core_process(t_node *a, t_node *b)
{
	int	total_nodes;
	int	pivot_index;

	(void)b;
	total_nodes = pre_indexing(&a);
	pivot_index = total_nodes / 2;
	printf("total = %d, pivot = %d\n", total_nodes, pivot_index);
	pb(&a, &b);
	debug_stack(&a, &b);
	pb(&a, &b);
	debug_stack(&a, &b);
	pb(&a, &b);
	debug_stack(&a, &b);
	pb(&a, &b);
	debug_stack(&a, &b);
	pb(&a, &b);
	debug_stack(&a, &b);
}
