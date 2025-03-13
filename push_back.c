/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:56:26 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 12:56:26 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int find_position(int *stack, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (stack[i] == value)
            return i;
    }
    return -1;
}

void push_back(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    while (*sizeB > 0) {
        int target = find_max_index(stackB, *sizeB);
        int target_pos = find_position(stackB, *sizeB, target);
        
        // Rotación optimizada para llevar el máximo al top
        rotate_to_top(stackB, sizeB, target, 'b');
        op_pa(stackA, sizeA, stackB, sizeB);
        
        // Aprovecha para hacer "rr" si es útil
        if (*sizeB > 0 && stackB[0] > stackA[0])
            op_rr(stackA, sizeA, stackB, sizeB);
    }
}