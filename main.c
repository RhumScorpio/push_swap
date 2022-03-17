/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:14:07 by clesaffr          #+#    #+#             */
/*   Updated: 2022/03/07 23:11:34 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	//malloc des deux stacks
	a = (t_stack *)malloc(sizeof(t_stack));
	stack_init(a);
	b = (t_stack *)malloc(sizeof(t_stack));
	stack_init(b);
	if (!push_args_safely(a, ac, av))
	{
		write(1, "Error\n", 6);
		stack_free(a);
		return (0);
	}
	else
	{
		//core_process(a, b);
		stack_free(a);
		stack_free(b);
	}
	return (0);
}
