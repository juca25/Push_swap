/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:21:23 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/06 17:47:26 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_qsort(int arr[], int low, int high)
{
	long long int	pi;

	if (low < high)
	{
		pi = ft_partition(arr, low, high);
		ft_qsort(arr, low, pi - 1);
		ft_qsort(arr, pi + 1, high);
	}
}

char **ft_assign_index_hex(int original[], int n) {
    int *sorted = malloc(n * sizeof(int));
    char **index;

    if (!sorted) exit(1);
    ft_memcpy(sorted, original, n * sizeof(int));
   	ft_qsort(sorted, 0, n - 1);
    index = malloc(n * sizeof(char *));
    if (!index) exit(1);

    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            if (original[i] == sorted[j]) {
                index[i] = ft_itoa_hex(j);
                break;
            }
            j++;
        }
        i++;
    }
    free(sorted);
    return index;
}