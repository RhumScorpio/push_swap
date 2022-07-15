/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_by_bits_in_two_stacks.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:03:08 by clesaffr          #+#    #+#             */
/*   Updated: 2022/05/31 16:03:15 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//RADIX SORT avec le bitshift

int    is_not_sorted(t_node **a)
{
    int     previous;
    t_node  *tmp;

    tmp = *a;
    previous = -1;
    //previous_number = -2147483648;
    while (tmp)
    {
        if (tmp->index_sorted >= previous)
            previous = tmp->index_sorted;
        else
            return (1);
        tmp = tmp->next;
    }
    printf("SORTED");
    return (0);
}

/*rappel on verifie grace a index->sorted si la position se termine par 0 ou par 1
fonction : main>core_process>bitshifting>checks-bit>sorts
arguments : t_node a **, t_node b **
*/

void    checks_bits(t_node **a, t_node **b, int bitshift_width)
{
    t_node  *tmp;
    t_node  *oper_a;
    int max_num;

    (void)b;
    tmp = *a;
    oper_a = *a;
    max_num = get_list_size(a);
    while (max_num--)
    {
        if ((tmp->index_sorted>>bitshift_width)&1)
            ra(&tmp);
        else
            pb(&tmp, b);
    }
    max_num = get_list_size(b);
    while (max_num--)
        pa(b, &tmp);
    *a = tmp;
}

void    bitshifting(t_node **a, t_node **b)
{
    int bitshift_width;

    bitshift_width = 0;
    while (bitshift_width < 32 && is_not_sorted(a))
    {
        checks_bits(a, b, bitshift_width);
        bitshift_width++;
    }
}
