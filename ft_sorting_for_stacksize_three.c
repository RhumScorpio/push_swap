/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_for_stacksize_three.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 13:46:58 by clesaffr          #+#    #+#             */
/*   Updated: 2022/07/23 13:47:15 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	use_first_second(t_node **tmp_secondary, int first, int second)
{
	if (first == 1 && second == -2)
		sa(tmp_secondary);
	else if (first == 1 && second == 1)
		sa(tmp_secondary);
	else if (first == -2 && second == 1)
		sa(tmp_secondary);
	else if (first == 2 && second == -1)
		ra(tmp_secondary);
	else if (first == -1 && second == 2)
		rra(tmp_secondary);
}

static void	check_what_is_sorted(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp_secondary;
	int		first;
	int		second;

	tmp = *a;
	tmp_secondary = tmp;
	while (is_not_sorted(&tmp_secondary))
	{
		first = tmp->index_sorted - tmp->next->index_sorted;
		tmp = tmp->next;
		second = tmp->index_sorted - tmp->next->index_sorted;
		use_first_second(&tmp_secondary, first, second);
	}
	*a = tmp_secondary;
}

void	sort_stack_of_twoa(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	if (tmp->index_sorted > tmp->next->index_sorted)
		sa(&tmp);
	*a = tmp;
}

void	sort_stack_of_three(t_node **a)
{
	int		total;
	int		i;

	total = get_list_size(a);
	i = 0;
	if (total < 2)
		return ;
	else if (total == 2)
		sort_stack_of_twoa(a);
	else if (total == 3)
		check_what_is_sorted(a);
}
