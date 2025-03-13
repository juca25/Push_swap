/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:29:46 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 14:33:28 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_array(int *src, int *dest, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	fill_normalized_array(int *arr, int *copy, int *norm, int size)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (arr[i] == copy[j])
			{
				norm[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
}

int	*normalize(int *arr, int a)
{
	int	*norm;
	int	*copy;

	norm = (int *)malloc(sizeof(int) * a);
	if (!norm)
		ft_error();
	copy = (int *)malloc(sizeof(int) * a);
	if (!copy)
	{
		free(norm);
		ft_error();
	}
	copy_array(arr, copy, a);
	bubble_sort(copy, a);
	fill_normalized_array(arr, copy, norm, a);
	free(copy);
	return (norm);
}