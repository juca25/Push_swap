/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:45:03 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/07 12:48:22 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void op_pa(char **stackA, int *sizeA, char **stackB, int *sizeB)
{
	char *value = stackB[0];
	int i = 0;
	while (i < *sizeB - 1)
	{
		stackB[i] = stackB[i + 1];
		i++;
	}
	(*sizeB)--;
	i = *sizeA;
	while (i > 0)
	{
		stackA[i] = stackA[i - 1];
		i--;
	}
	stackA[0] = value;
	(*sizeA)++;
	printf("pa\n");
}