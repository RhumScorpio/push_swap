/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:17:54 by clesaffr          #+#    #+#             */
/*   Updated: 2022/01/07 19:19:13 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		core

int		core_if_do_basic_sort(t_stack *s)
{
	if (stack_0_nodes_till_bottom_or_pivot(s))
		return (1);
	if (stack_1_nodes_till_bottom_or_pivot(s))
		return (1);
	if (stack_2_nodes_till_bottom_or_pivot(s))
		return (1);
	if (stack_3_nodes_till_bottom_or_pivot(s))
		return (1);
	return (0);
}

void	core_basic_sort_a(t_stack *s)
{
	if (stack_0_nodes_till_bottom_or_pivot(s))
		return ;
	else if (stack_1_nodes_till_bottom_or_pivot(s))
	{
		stack_set_top_is_sorted(s);
		return ;
	}
	else if (stack_2_nodes_till_bottom_or_pivot(s))
	{
		stack_set_node_is_sorted(s->top);
		stack_set_node_is_sorted(s->top->next);
		if (s->top->data > s->top->next->data)
			sa(s);
	}
	else if (stack_3_nodes_till_bottom_or_pivot(s))
	{
		stack_set_node_is_sorted(s->top);
		stack_set_node_is_sorted(s->top->next);
		stack_set_node_is_sorted(s->top->next->next);
		core_basic_sort_3_nodes(NULL, s);
	}
}

void	core_process(t_stack *a, t_stack *b)
{
	int		stop_process;

	stop_process = 0;
	while (!stop_process)
	{
		core_a2b_while(a, b);
		core_basic_sort_a(a);
		if (stack_is_empty(b))
		{
			stop_process = 1;
			continue ;
		}
		core_b2a_while(a, b);
	}
}
