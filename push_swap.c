/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:43:50 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 16:48:10 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int find_max_index(int *stack, int size)
{
    int max = stack[0], idx = 0, i = 1;
    while(i < size)
    {
        if(stack[i] > max)
        {
            max = stack[i];
            idx = i;
        }
        i++;
    }
    return idx;
}

int find_closest_in_range(int *stack, int size, int min, int max) {
    int closest = INT_MAX;
    int closest_idx = 0;
    
    for (int i = 0; i < size; i++) {
        if (stack[i] >= min && stack[i] <= max) {
            if (abs(i - 0) < closest_idx) {
                closest = stack[i];
                closest_idx = i;
            }
        }
    }
    return closest;
}

void chunk_sort(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    int chunk_size;// Ajuste óptimo para 500 números
    int max_chunks = (*sizeA / chunk_size) + 1;
    
    if(i < 100)
	   chunk_size = 15;
	else if(i < 500)
    	chunk_size = 33;
    for (int chunk = 0; chunk < max_chunks; chunk++) {
        int current_min = chunk * chunk_size;
        int current_max = (chunk + 1) * chunk_size;
        
        for (int i = 0; i < chunk_size; i++) {
            int closest = find_closest_in_range(stackA, *sizeA, current_min, current_max);
            rotate_to_top(stackA, sizeA, closest, 'a');
            op_pb(stackA, sizeA, stackB, sizeB);
            if (*sizeB > 1 && stackB[0] < stackB[1])
                op_rb(stackB, sizeB); // Mantiene B ordenado
        }
    }
}

