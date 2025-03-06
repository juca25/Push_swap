/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:43:46 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/06 16:24:12 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *stack, int size)
{
	int	temp;
	if(stack == NULL || size < 2)
		return ;
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void ft_rotate(int *stack, int size) {
    if (size <= 1) return;
    int first = stack[0];
    int i = 0;
    while (i < size - 1) {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[size - 1] = first;
}

void ft_reverse_rotate(int *stack, int size) {
    int temp;
    int i;
    if (stack == NULL || size < 2)
        return;
    temp = stack[size - 1];
    i = size - 1;
    while(i > 0) {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[0] = temp;
}

void push_b(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    if (*sizeA <= 0) return;
    stackB[*sizeB] = stackA[0];
    (*sizeB)++;
    int i = 0;
    while (i < *sizeA - 1) {
        stackA[i] = stackA[i + 1];
        i++;
    }
    (*sizeA)--;
}

void push_a(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    if (*sizeB <= 0) return;
    int i = *sizeA;
    while (i > 0) {
        stackA[i] = stackA[i - 1];
        i--;
    }
    stackA[0] = stackB[0];
    (*sizeA)++;
    i = 0;
    while (i < *sizeB - 1) {
        stackB[i] = stackB[i + 1];
        i++;
    }
    (*sizeB)--;
}

