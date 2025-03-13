/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:39:28 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 16:39:28 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_rra(int *stackA, int *sizeA)
{
    if (stackA == NULL || *sizeA < 2)
        return;
    
    int temp = stackA[*sizeA - 1];
    int i = *sizeA - 1;
    
    while (i > 0)
    {
        stackA[i] = stackA[i - 1];  // Desplaza todos los elementos hacia la derecha
        i--;
    }
    
    stackA[0] = temp;  // Coloca el último elemento al principio
    printf("rra\n");
}