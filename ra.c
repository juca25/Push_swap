/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:41:02 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/07 12:48:43 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_ra(char **stack, int *size)
{
	char *temp = stack[0];
	int i = 0;
	while (i < *size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[*size - 1] = temp;
	printf("ra\n");
}