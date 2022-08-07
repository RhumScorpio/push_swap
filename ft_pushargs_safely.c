/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushargs_safely.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:11:29 by clesaffr          #+#    #+#             */
/*   Updated: 2022/07/10 15:10:33 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

int	ft_whitespace(char c)
{
	if (c == ' ' || (c >= 7 && c <= 13))
		return (1);
	return (0);
}

int	ft_splitting_args(t_node **a, char *str)
{
	char	**split;
	int		i;
	int		data;
	int		checked;

	data = 0;
	checked = 0;
	split = ft_split(str, ' ');
	i = ft_size_of_doubletab(split);
	if (!split)
		return (0);
	while (i && i >= 0)
	{
		i--;
		checked = is_str_int(split[i]);
		data = ft_atoi(split[i]);
		if (is_duplicated(a, data) || !checked)
		{
			ft_free_doubletab(split);
			return (0);
		}
		node_push(a, data);
	}
	ft_free_doubletab(split);
	return (1);
}

int	ft_push_str(t_node **a, char **split, int ac)
{	
	int	i;
	int	data;
	int	checked;

	i = ac - 1;
	data = 0;
	checked = 0;
	if (!split)
		return (0);
	while (i && i > 0)
	{
		checked = is_str_int(split[i]);
		data = ft_atoi(split[i]);
		if (is_duplicated(a, data) || !checked)
			return (0);
		node_push(a, data);
		i--;
	}
	return (1);
}

int	push_args_safely(t_node **a, int ac, char **av)
{
	if (ac == 1 || *av == NULL)
		return (1);
	else if (ac == 2)
		return (ft_splitting_args(a, av[1]));
	else if (ac > 2)
		return (ft_push_str(a, av, ac));
	return (1);
}
