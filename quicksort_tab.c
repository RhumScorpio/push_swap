/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clesaffr <clesaffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:47:11 by clesaffr          #+#    #+#             */
/*   Updated: 2021/04/06 01:40:15 by clesaffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_swap(int str[MAX], int	*start, int *end)
{
		int	tmp;

		tmp = str[*start];
		str[*start] = str[*end];
		str[*end] = tmp;
}

int		partition(int str[MAX], int start, int end, int pivot)
{
	int j;
	int i;

	i = start;
	j = end;
		while (1)
		{
				while (i < end && str[end] > pivot)
						end -= 1;
				while (str[start] < pivot)
						start += 1;
				if (end <= start)
						break;
				ft_swap(str[MAX], &start, &end);
		}
		return (end);
}

int quicksort(int str[MAX], int start, int end)
{
	int pivot;
	int middle;

	middle = 0;
	if	(start < end)
	{
				pivot = str[start];
				middle = partition(str[MAX], start, end, pivot);
				
				quicksort(str[MAX], start, middle - 1);
				quicksort(str[MAX], middle + 1, end);
	}
	return (0);
}

void printres(int str[MAX])
{
		int z;

		z = 0;
		while (z < 8)
		{
				printf("%d, ", str[z]);
				z++;
		}
		printf("\n");
}

int		main()
{
		int start;
		int end;
		int str[MAX];

		//DECLARATION VARIABLES
		start = 0;
		end = MAX - 1;
		str[MAX] = {7, 15, 12, 3, 2, 1, 5, 16};
		printres(str[MAX]);
		quicksort(str[MAX], start, end);
		printres(str[MAX]);
		return (0);
}
