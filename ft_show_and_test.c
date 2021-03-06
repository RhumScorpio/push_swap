/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_and_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:27:39 by clesaffr          #+#    #+#             */
/*   Updated: 2022/06/15 23:01:33 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_stack(t_node *a)
{
	printf("SHOW STACK\n");
	while (a)
	{
		printf("[%d]\n", a->number);
		a = a->next;
	}
}

void	debug(t_node *a, char c)
{
	t_node	*tmp;

	if (!a)
		return ;
	tmp = a;
	printf("DEBUG %c\n", c);
	while (tmp)
	{
		printf("number = %d, index[%d]\n",
			tmp->number, tmp->index_sorted);
		printf("%p\n", tmp->next);
		tmp = tmp->next;
	}
}

void	debug_stack(t_node *a, t_node *b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (!a | !b)
		return ;
	tmp = a;
	tmp2 = b;
	printf("STACK A\n");
	while (tmp)
	{
		printf("[%d]", tmp->number);
		tmp = tmp->next;
	}
	printf("\n");
	printf("STACK B\n");
	while (tmp2)
	{
		printf("[%d]", tmp2->number);
		tmp2 = tmp2->next;
	}
	printf("\n");
}
