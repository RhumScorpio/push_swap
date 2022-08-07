/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_for_stacksize_five.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:35:42 by clesaffr          #+#    #+#             */
/*   Updated: 2022/07/09 20:36:24 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_pivot(t_node **a, int *i)
{
	int		total_nodes;

	total_nodes = get_list_size(a);
	*i = total_nodes;
	return (total_nodes / 2);
}

void	sort_stack_of_five(t_node **a, t_node **b)
{
	int		i;
	int		p;
	t_node	*tmp;

	tmp = *a;
	p = find_pivot(&tmp, &i);
	while (i != 0)
	{
		if (tmp->index_sorted < p)
			pb(&tmp, b);
		else
			ra(&tmp);
		i--;
	}
	sort_stack_of_three(&tmp);
	sort_stackb(b);
	i = 0;
	while (i < p)
	{
		pa(b, &tmp);
		i++;
	}
	*a = tmp;
}
