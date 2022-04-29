/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_till_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:10:44 by clesaffr          #+#    #+#             */
/*   Updated: 2022/04/27 15:11:40 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     if_node_is_last(t_node *s)
{
    if (!s)
        return (0);
    if (s->next == NULL)
        return (1);
    return (0);
}

int     if_node_is_nexttolast(t_node *s)
{
    if (if_node_is_last(s->next))
        return (1);
    return (0);
}