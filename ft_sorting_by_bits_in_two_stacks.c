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
//des unites jusqu'au million
//stack a = 1 / stack b = 0

void    pushing_in_b(t_node **a, t_node **b)
{
    int nuwidth;
    int i;
    t_node  *tmp;

    (void)b;
    nuwidth = 0;
    i = 0;
    tmp = *a;
    while (tmp)
    {
        printf("analyse a[%d]\n", i);
         while (nuwidth <= 31)
        {
            printf("%d|", (tmp->index_sorted>>nuwidth)&1);
            nuwidth++;
        }
        i++;
        tmp = tmp->next;
        nuwidth = 0;
        printf("\n");
    }
   
}
