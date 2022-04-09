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

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = malloc_the_node();
	b = malloc_the_node();
	if (!a || !b)
		return (0);
	if (!push_args_safely(&a, ac, av))
	{
		write(1, "Error\n", 6);
		node_free(a);
		return (0);
	}
	printf("ISDIGIT = %d\n", ft_isdigit('9'));
	show_stack(a);
	core_process(a, b);
	node_free(a);
	node_free(b);
	return (0);
}
