/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_operators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:43:46 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/03 16:14:57 by juan-ser         ###   ########.fr       */
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

void ft_rotate(int *stack, int size)
{
	int	temp;
	int	i;
	if(stack == NULL || size < 2)
		return ;
	temp = stack[0];
	i = size - 1;
	while(i > 0)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = temp;
}

void	ft_reverse_rotate(int *stack, int size)
{
	int	temp;
	int	i;
	if (stack == NULL || size < 2)
		return ;
	temp = stack[size - 1];
	i = size - 1;
	while(i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
}

void	push_b(int *stackA, int *sizeA, int *stackB, int *sizeB)
{
	int	i;
	if (stackA == NULL || stackB == NULL || sizeA == NULL || sizeB == NULL || *sizeB >= MAX_SIZE || *sizeA == 0)
        return;
	i = *sizeB;
	while(i > 0)
	{
		stackB[i] = stackB[i + 1];
		i--;
	}
	stackB[0] = stackA[0];
	(*sizeB)++;
	i = 0;
	while(i < *sizeA - 1)
	{
		stackA[i] = stackA[i + 1];
		i++;
	}
	(*sizeA)--;
}

void	push_a(int *stackA, int *sizeA, int *stackB, int *sizeB)
{
	int	i;
	if (stackA == NULL || stackB == NULL || sizeA == NULL || sizeB == NULL || *sizeA >= MAX_SIZE || *sizeB == 0)
        return;
	i = *sizeA;
	while(i > 0)
	{
		stackA[i] = stackA[i - 1];
		i--;
	}
	stackA[0] = stackB[0];
	(*sizeA)++;
	i = 0;
	while(i < *sizeB)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	(*sizeB)--;
}