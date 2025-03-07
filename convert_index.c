/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:38:51 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/07 12:40:02 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int ft_partition(int arr[], int low, int high)
{
	int pivot = arr[high], i = low - 1, j = low, tmp;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		j++;
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	return (i + 1);
}

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