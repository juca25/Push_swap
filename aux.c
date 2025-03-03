/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:49:03 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/03 16:03:16 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;
	
	if(!str)
		return (0);
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

void	ft_swap_int(int *a, int *b)
{
	if(a == NULL || b == NULL)
		return ;
	int	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	
	if(arr == NULL)
		return -1;
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

char	*ft_itoa_hex(unsigned int num)
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
	while(num > 0)
	{
		buffer[--i] = hex_digits[num % 16];
		num /= 16;
	}
	result = malloc(9 - i);
	if(!result)
	{
		perror("Error de asignación de memoria");
		exit(1);
	}
	j = 0;
	while(buffer[i])
		result[j++] = buffer[i++];
	result[j] = '\0';
	return (result);
}

void free_index(char **index, int n)
{
	int	i;
	if(index == NULL)
		return ;
	i = 0;
	while(i < n)
	{
		if(index[i] != NULL)
			free(index[i]);
		i++;
	}
	free(index);
}
