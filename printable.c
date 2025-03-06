/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:37:51 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/06 12:03:23 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stack(int *stack, int size)
{
	int	i;

	i  = 0;
	while(i < size)
	{
		printf("%d ", stack[i]);
		i++;
	}
	printf("\n");
}
void ft_print_stack_hex(int *stack, int size)
{
	int	i;

	i  = 0;
	while(i < size)
	{
		printf("%X ", stack[i]);
		i++;
	}
	printf("\n");
}

void	ft_print_index_hex(char **index, int n)
{
	int	i;
	i = 0;
	while(i < n)
	{
		printf("%s ", index[i]);
		i++;
	}
	printf("\n");
}

void ft_print_array(int arr[], int size)
{
	int i;
	i = 0;
	while(i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}