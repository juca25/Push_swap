/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:49:03 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/03 13:46:15 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;
	
	i = 0;
	sign = 1;
	while(str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

static void	ft_swap_int(int *a, int *b)
{
	int	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

static int	ft_partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	
	pivot = arr[high];
	i = low - 1;
	j = low;
	while(j < high)
	{
		if(arr[j] < pivot)
		{
			i++;
			ft_swap_int(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap_int(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	ft_qsort(int arr[], int low, int high)
{
	int	pi;
	if (low < high)
	{
		pi = ft_partition(arr, low, high);
		ft_qsort(arr, low, pi - 1);
		ft_qsort(arr, pi + 1, high);
	}
}

static char	*ft_itoa_hex(unsigned int num)
{
	char	*hex_digits;
	char	buffer[9];
	int		i;
	char	*result;
	int		j;

	hex_digits= "0123456789ABCDEF";
	i = 8;

	buffer[i] = '\0';
	if(num == 0)
		buffer[--i] = '0';
	while(num)
	{
		buffer[--i] = hex_digits[num % 16];
		num /= 16;
	}
	result = malloc(9 - i);
	if(!result)
		exit(1);
	j = 0;
	while(buffer[i])
		result[j++] = buffer[i++];
	result[j] = '\0';
	return (result);
}

static char	**ft_assign_index_hex(int original[], int sorted[], int n)
{
	char **index;
	int	i;
	int	j;
	
	index = malloc(n * sizeof(char *));
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

static void	ft_print_index_hex(char **index, int n)
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

static void free_index(char **index, int n)
{
	int	i;

	i = 0;
	while(i < n)
	{
		free(index[i]);
		i++;
	}
	free(index);
}

static void ft_print_array(int arr[], int size)
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

int main(void)
{
    int original[] = {50, 20, 40, 10, 30, 1, 1241, 12511, 67, 2563, 123, 234, 32, 23423, 23, 56, 5665};
    long long int n = 20;
    int i;
    
    int *sorted = malloc(n * sizeof(int));
    if (!sorted)
        exit(1);
    for (i = 0; i < n; i++)
        sorted[i] = original[i];
    
    ft_qsort(sorted, 0, n - 1);
    
    printf("Arreglo desordenado :\n");
    for (i = 0; i < n; i++)
        printf("%d ", original[i]);
    printf("\n");
	
    printf("Arreglo ordenado (copia):\n");
    for (i = 0; i < n; i++)
        printf("%d ", sorted[i]);
    printf("\n");

    char **hex_indices = ft_assign_index_hex(original, sorted, n);
    
    printf("Índices en hexadecimal:\n");
    ft_print_index_hex(hex_indices, n);
    
    free(sorted);
    free_index(hex_indices, n);
    return 0;
}