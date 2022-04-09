/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushargs_safely.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:11:29 by clesaffr          #+#    #+#             */
/*   Updated: 2022/04/09 14:11:35 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	is_int_range(char *s)
{
	long long	d;

	d = ft_char_to_integer(s);
	if (d > (long long)(2147483647) || d < (long long)(-2147483648))
		return (0);
	return (1);
}

static int	is_str_int(char *s)
{
	if (!while_digit(s))
		return (0);
	if (!is_int_range(s))
		return (0);
	return (1);
}

static int	is_duplicated(t_node **a, int data)
{
	t_node	*n;

	n = *a;
	while (n)
	{
		if (n->number == data)
			return (1);
		n = n->next;
	}
	return (0);
}

int	push_args_safely(t_node **a, int ac, char **av)
{
	int		i;
	int		data;
	char	*str;

	i = 1;
	while (i < ac)
	{
		str = av[ac - i];
		if (!is_str_int(str))
			return (0);
		data = ft_atoi(str);
		if (is_duplicated(a, data))
			return (0);
		node_push(a, data);
		i++;
	}
	return (1);
}
