/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:28:04 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/07 11:35:22 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bubble_sort(int *arr, int n) 
{
	int	i;
	int	j;
	int	temp;
	
	i = 0;
	while(i < n - 1) 
	{
		j = 0;
		while(j < n - i - 1) 
		{
			if(arr[j] > arr[j+1]) 
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			j++;
		}
		i++;
	}
}