/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:14:07 by clesaffr          #+#    #+#             */
/*   Updated: 2022/04/09 22:13:58 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*malloc_the_node(void)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
	{
		printf("Error in memory allocation.\n");
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (!push_args_safely(&a, ac, av))
	{
		write(1, "Error\n", 6);
		node_free(a);
		return (0);
	}
	show_stack(a);
	core_process(a, b);
	node_free(a);
	node_free(b);
	return (0);
}
