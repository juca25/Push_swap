/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:43:50 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/07 13:07:47 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int get_hex_digit(char *s, int pos, int max_len)
{
	int len = 0, i = 0;
	while (s[i])
	{
		len++;
		i++;
	}
	int index = len - 1 - pos;
	char c = (index < 0) ? '0' : s[index];
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return 0;
}

int *get_digit_range(char **stack, int size, int pos, int max_len)
{
	int *range = malloc(2 * sizeof(int));
	int i = 0, d, min = 16, max = -1;
	while (i < size)
	{
		d = get_hex_digit(stack[i], pos, max_len);
		if (d < min)
			min = d;
		if (d > max)
			max = d;
		i++;
	}
	range[0] = min;
	range[1] = max;
	return range;
}

int get_max_len(char **stack, int size)
{
	int max = 0, i = 0, len, j;
	while (i < size)
	{
		len = 0;
		j = 0;
		while (stack[i][j])
		{
			len++;
			j++;
		}
		if (len > max)
			max = len;
		i++;
	}
	return max;
}

void radix_sort_hex_str(char **stackA, char **stackB, int *sizes, int max_len)
{
	int pos = 0;
	while (pos < max_len)
	{
		int *range = get_digit_range(stackA, sizes[0], pos, max_len);
		int bucket = range[1];
		while (bucket >= range[0])
		{
			int count = sizes[0], processed = 0;
			while (processed < count)
			{
				if (get_hex_digit(stackA[0], pos, max_len) == bucket)
					op_pb(stackA, &sizes[0], stackB, sizes);
				else
					op_ra(stackA, &sizes[0]);
				processed++;
			}
			while (sizes[1] > 0)
				op_pa(stackA, &sizes[0], stackB, sizes);
			bucket--;
		}
		free(range);
		pos++;
	}
}

