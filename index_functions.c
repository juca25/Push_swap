/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:21:23 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/03 15:58:53 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_qsort(int arr[], int low, int high)
{
	int	pi;
	if (low < high)
	{
		pi = ft_partition(arr, low, high);
		ft_qsort(arr, low, pi - 1);
		ft_qsort(arr, pi + 1, high);
	}
}

char	**ft_assign_index_hex(int original[], int sorted[], int n)
{
	char **index;
	int	i;
	int	j;
	
	index = malloc(n * sizeof(char *));
	if(!index)
	{
		perror("Error de asignación de memoria");
		exit(1);
	}
	if(!index)
		exit(1);
	i = 0;
	while(i < n)
	{
		j = 0;
		while(j < n)
		{
			if(original[i] == sorted[j])
				break;
			j++;
		}
		index[i] = ft_itoa_hex((unsigned int)j);
		i++;
	}
	return (index);
}