/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespaces_parsing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:09:44 by clesaffr          #+#    #+#             */
/*   Updated: 2022/04/09 14:09:53 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	while_digit(char *s)
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

int	is_str_int(char *s)
{
	if (!while_digit(s))
		return (0);
	if (!is_int_range(s))
		return (0);
	return (1);
}

int	if_just_sign(char *s)
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
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}