/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:49:03 by juan-ser          #+#    #+#             */
/*   Updated: 2025/02/27 12:36:11 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

t_node *create_node(int value)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	return (new_node);
}

void push_node(t_node **stack, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

int *copy_stack_to_array(t_node *stack, int *size)
{
	int count;
	t_node *temp;
	int i;
	
	count = 0;
	temp = stack;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
	*size = count;
	int *array = (int *)malloc(sizeof(int) * count);
	if (!array)
		exit(1);
	i = 0;
	while(stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
	return (array);
}

void	swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int *array, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
			swap_int(&array[++i], &array[j]);
		j++;
	}
	swap_int(&array[i + 1], &array[high]);
	return (i + 1);
}

void quick_sort(int *array, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high);
		quick_sort(array, low, pi - 1);
		quick_sort(array, pi + 1, high);
	}
}

void print_array(int *array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	printf("\n");
}
void free_stack(t_node *stack)
{
	t_node *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int main(void)
{
	t_node *stack = NULL;
	
	push_node(&stack, create_node(333));
	push_node(&stack, create_node(2));
	push_node(&stack, create_node(15));
	int size;
	int *array = copy_stack_to_array(stack, &size);
	
	printf("Array:\n");
	print_array(array, size);

	quick_sort(array, 0, size - 1);
	
	printf("Sorted Array:\n");
	print_array(array, size);

	free(array);
	free_stack(stack);
}