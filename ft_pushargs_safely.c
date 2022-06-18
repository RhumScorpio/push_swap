/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushargs_safely.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:11:29 by clesaffr          #+#    #+#             */
/*   Updated: 2022/06/15 23:00:43 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	if_just_sign(char *s)
{
	int	i;

	i = 0;
	while (ft_whitespace(s[i]) == 1)
		i++;
	while (s[i] && (s[i] == '-' || s[i] == '+'))
	{
		if (i != 0 && s[i] != s[i - 1])
			return (0);
		i++;
	}
	if (i == ft_strlen(s))
		return (0);
	return (1);
}

static int	is_int_range(char *s)
{
	long long	d;

	if (!if_just_sign(s))
		return (0);
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

int	ft_splitting_args(t_node **a, char *str)
{
	char	**split;
	int		data;
	int		i;

	i = 0;
	data = 0;
	split = ft_split(str, ' ');
	if (!split)
		return (0);
	while (split[i])
	{
		data = ft_atoi(split[i]);
		if (is_duplicated(a, data))
				return (0);
		node_push(a, data);
		i++;
	}
	return (1);
}

int	push_args_safely(t_node **a, int ac, char **av)
{
	int		i;
	int		data;
	char	*str;

	i = 1;
	if (ac == 1 || *av == NULL)
		return (0);
	else if (ac == 2)
		return (ft_splitting_args(a, av[1]));
	else
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
