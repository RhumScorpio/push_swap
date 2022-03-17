/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:15:23 by clesaffr          #+#    #+#             */
/*   Updated: 2022/03/07 23:35:33 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_whitespace(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' 
		|| c == '\b' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

long long	ft_char_to_integer(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	while (ft_whitespace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] - '0' >= 0 && str[i] - '0' <= 9))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

static int	is_digit(char *s)
{
	char	*p;

	p = s;
	while (*p != '\0')
	{
		if (!(ft_isdigit(*p) || *p == '+' || *p == '-'))
			return (0);
		p++;
	}
	return (1);
}

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
	if (!is_digit(s))
		return (0);
	if (!is_int_range(s))
		return (0);
	return (1);
}

static int	is_duplicated(t_stack *a, int data)
{
	t_node	*n;

	n = a->top;
	while (n)
	{
		if (n->data == data)
			return (1);
		n = n->next;
	}
	return (0);
}
//push args = stack a remplissage
int	push_args_safely(t_stack *a, int ac, char **av)
{
	int i;
	int data;
	char *str;

	i = 1;
	while (i < ac)
	{
		str = av[ac - i];
		if (!is_str_int(str))
			return (0);
		data = ft_atoi(str);
		if (is_duplicated(a, data))
			return (0);
		stack_push(a, data);
		i++;
	}
	return (1);
}

