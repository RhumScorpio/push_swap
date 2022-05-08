/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:36:19 by clesaffr          #+#    #+#             */
/*   Updated: 2022/05/08 18:36:32 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_addback(t_node *b, t_node *add)
{
	printf("find last to append\n");
	while (b->next != NULL)
		b = b->next;
	b->next = add;
	add->next = NULL;
}

int		get_list_size(t_node **list)
{
	t_node	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int		list_too_short(t_node **b)
{
	if (get_list_size(b) < 2)
		return (1);
	return (0);
}