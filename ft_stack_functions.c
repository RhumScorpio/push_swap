/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:49:35 by clesaffr          #+#    #+#             */
/*   Updated: 2022/03/07 23:01:50 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	stack_init(t_stack *s)
{
	s->top = NULL;
}

int		stack_is_empty(t_stack *s)
{
	return (s->top == NULL);
}

void	stack_free(t_stack *s)
{
	t_node	*top;

	while (!stack_is_empty(s))
	{
		top = stack_pop(s);
		free(top);
	}
	free(s);
}

t_node	*stack_pop(t_stack *s)
{
	t_node	*top_node;

	if (stack_is_empty(s))
		return (NULL);
	top_node = s->top;
	s->top = top_node->next;
	top_node->next = NULL;
	return (top_node);
}
//for pushing args into a
void	stack_push(t_stack	*s, int d)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->data = d;
	tmp->next = NULL;
	tmp->is_pivot = 0;
	tmp->by_pivot = 0;
	tmp->is_sorted = 0;
	if (stack_is_empty(s))
		s->top = tmp;
	else
	{
		tmp->next = s->top;
		s->top = tmp;
	}
}

int		stack_peek_data(t_stack *s)
{
	if (stack_is_empty(s))
		return (-1);
	return (s->top->data);
}

int		stack_set_top_pivot(t_stack *s)
{
	s->top->is_pivot = 1;
	return (stack_peek_data(s));
}

int		stack_is_node_pivot(t_node *n)
{
	return (n->is_pivot == 1);
}

int		stack_is_top_pivot(t_stack *s)
{
	return (n->is_pivot == 1);
}

int		stack_0_nodes_till_bottom_or_pivot(t_stack *s)
{
	return (stack_is_empty(s) || stack_is_top_pivot(s));
}
//ONE TWO THREE NODES TILL PIVOT
