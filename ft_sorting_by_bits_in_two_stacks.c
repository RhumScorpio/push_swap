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

//fonctions pour une stack inferieure a 5
void    max_five()
{
    
}

/*rappel on verifie grace a index->sorted si la position se termine par 0 ou par 1
fonction : main>core_process>bitshifting>checks-bit>sorts
arguments : t_node a **, t_node b **
*/

//fonction pour faire pb

//fonction pour faire ra

//fonction pour faire pa

//fonction qui check le bit

void    checks_bits(t_node **a, t_node **b, int bitshift_width)
{
    t_node  *tmp;
    t_node  *oper_a;
    int max_num;
    int i;

    (void)b;
    tmp = *a;
    debug(tmp, 'T');

    oper_a = *a;
    max_num = get_list_size(a);
        debug(tmp, 'T');

    i = 0;
    while (i < max_num)
    {
        printf("NUM %d, IND %d\n", tmp->number, tmp->index_sorted);
        if ((tmp->index_sorted>>bitshift_width)&1)
        {
          printf("PB\n");
            pb(&tmp, b);
        }
        else
        {
          printf("RA\n");
           ra(&tmp);
        }
        i++;
        //tmp = tmp->next;
    }
        debug(tmp, 'T');

}

void    bitshifting(t_node **a, t_node **b)
{
    int bitshift_width;

    bitshift_width = 0;
   // while (bitshift_width < 32)
   // {
        checks_bits(a, b, bitshift_width);
        bitshift_width++;
    debug(*a, 'A');

   // }
}
