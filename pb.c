/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:42:42 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/07 12:48:32 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_pb(char **stackA, int *sizeA, char **stackB, int *sizeB)
{
	char *value = stackA[0];
	int i = 0;
	while (i < *sizeA - 1)
	{
		stackA[i] = stackA[i + 1];
		i++;
	}
	(*sizeA)--;
	i = *sizeB;
	while (i > 0)
	{
		stackB[i] = stackB[i - 1];
		i--;
	}
	stackB[0] = value;
	(*sizeB)++;
	printf("pb\n");
}