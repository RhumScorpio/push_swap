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

	if(!*b)
		return ;
	temp_b = *b;
	temp_b->next = NULL;
	if (b[0]->next)
		*b = b[0]->next;
	
	ft_putstr("rb\n");
}

void	core_process(t_node **a, t_node **b)
{
	int	total_nodes;
	int	pivot_index;

	total_nodes = pre_indexing(a);
	pivot_index = total_nodes / 2;
	printf("total = %d, pivot = %d\n", total_nodes, pivot_index);
	pb(a, b);
	debug_stack(a, b);
	pb(a, b);
	debug_stack(a, b);
	pb(a, b);
	debug_stack(a, b);
	pb(a, b);
	debug_stack(a, b);
	sb(b);
	debug_stack(a, b);
	rb(b);
	debug_stack(a, b);
}
