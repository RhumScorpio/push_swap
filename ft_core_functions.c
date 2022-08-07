/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:58:29 by clesaffr          #+#    #+#             */
/*   Updated: 2022/07/10 14:51:18 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pre_indexing(t_node **a)
{
	t_node			*tmp;
	t_node			*compare;
	unsigned int	i;

	if (!*a)
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
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	core_process(t_node **a, t_node **b)
{
	int	total_nodes;

	total_nodes = pre_indexing(a);
	if (!total_nodes || !(is_not_sorted(a)))
		return ;
	else if (total_nodes <= 3)
		sort_stack_of_three(a);
	else if (total_nodes <= 6)
		sort_stack_of_five(a, b);
	else
		bitshifting(a, b);
}
