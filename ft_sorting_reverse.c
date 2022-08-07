/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 20:09:56 by clesaffr          #+#    #+#             */
/*   Updated: 2022/08/01 20:10:22 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_not_sorted_rev(t_node **b)
{
	t_node	*tmp;
	int		previous;

	tmp = *b;
	previous = 2147483647;
	while (tmp)
	{
		if (tmp->index_sorted <= previous)
			previous = tmp->index_sorted;
		else
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static void	use_first_second(t_node **tmp_secondary, int first, int second)
{
	if (first == 1 && second == -2)
		rrb(tmp_secondary);
	else if (first == -1 && second == -1)
		sb(tmp_secondary);
	else if (first == -2 && second == 1)
		rb(tmp_secondary);
	else if (first == 2 && second == -1)
		sb(tmp_secondary);
	else if (first == -1 && second == 2)
		sb(tmp_secondary);
}

static void	check_what_is_sorted(t_node **b)
{
	t_node	*tmp;
	t_node	*tmp_secondary;
	int		first;
	int		second;

	tmp = *b;
	tmp_secondary = tmp;
	while (is_not_sorted_rev(&tmp_secondary))
	{
		first = tmp->index_sorted - tmp->next->index_sorted;
		tmp = tmp->next;
		second = tmp->index_sorted - tmp->next->index_sorted;
		use_first_second(&tmp_secondary, first, second);
	}
	*b = tmp_secondary;
}

void	sort_stack_of_twob(t_node **b)
{
	t_node	*tmp;

	tmp = *b;
	if (tmp->index_sorted < tmp->next->index_sorted)
		sb(&tmp);
	*b = tmp;
}

void	sort_stackb(t_node **b)
{
	int		total;
	int		i;

	total = get_list_size(b);
	i = 0;
	if (total < 2)
		return ;
	else if (total == 2)
		sort_stack_of_twob(b);
	else if (total == 3)
		check_what_is_sorted(b);
}
