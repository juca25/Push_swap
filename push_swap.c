/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:43:50 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/21 16:59:03 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max(int *stack, int size) {
    int max = stack[0], i;
    for (i = 1; i < size; i++) {
        if (stack[i] > max)
            max = stack[i];
    }
    return max;
}

/* Cuenta los bits necesarios para representar 'num' */
int count_bits(int num) {
    int bits = 0;
    while (num >> bits)
        bits++;
    return bits;
}

/* Radix Sort bitwise: para cada bit de los números normalizados */
void radix_sort(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    int max = stackA[0], i, j;
    for (i = 1; i < *sizeA; i++) {
        if (stackA[i] > max)
            max = stackA[i];
    }
    int bits = count_bits(max);
    int passes = (bits + 1) / 2; // redondeo hacia arriba para procesar 2 bits por pasada
    for (i = 0; i < passes; i++) {
        int count = *sizeA;  // número de elementos a procesar en esta pasada
        for (j = 0; j < count; j++) {
            int digit = (stackA[0] >> (2 * i)) & 3; // extrae 2 bits en la posición 2*i
            if (digit == 0)
                op_pb(stackA, sizeA, stackB, sizeB);
            else
                op_ra(stackA, sizeA);
        }
        while (*sizeB > 0)
            op_pa(stackA, sizeA, stackB, sizeB);
    }
}
