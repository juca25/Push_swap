/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:43:50 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/20 16:58:37 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_min_max(int *stack, int size, int *min, int *max) {
    int i;
    *min = stack[0];
    *max = stack[0];
    for (i = 1; i < size; i++) {
        if (stack[i] < *min)
            *min = stack[i];
        if (stack[i] > *max)
            *max = stack[i];
    }
}

int count_chunk(int *stack, int size, int low, int high) {
    int count = 0, i = 0;
    while (i < size) {
        if (stack[i] >= low && stack[i] < high)
            count++;
        i++;
    }
    return count;
}
int find_closest_in_range(int *stack, int size, int low, int high) {
    int closest = INT_MAX;
    int closest_idx = -1;
    for (int i = 0; i < size; i++) {
        if (stack[i] >= low && stack[i] <= high) {
            if (abs(i - 0) < closest_idx || closest_idx == -1) {
                closest = stack[i];
                closest_idx = i;
            }
        }
    }
    return closest;
}

// Rota el stack para llevar un elemento al top (usa ra/rra)
void rotate_to_top(int *stack, int *size, int value) {
    int pos = -1;
    for (int i = 0; i < *size; i++) {
        if (stack[i] == value) {
            pos = i;
            break;
        }
    }
    if (pos <= *size / 2) {
        for (int i = 0; i < pos; i++) op_ra(stack, size);
    } else {
        for (int i = 0; i < *size - pos; i++) op_rra(stack, size);
    }
}


void chunk_sort(int *stackA, int *sizeA, int *stackB, int *sizeB, int n, int num_chunks) {
    int min, max, chunk_size, current_max, current_min, i, closest;
    find_min_max(stackA, *sizeA, &min, &max);

    chunk_size = (max - min + 1) / num_chunks;
    current_max = max;
    current_min = current_max - chunk_size + 1;

    for (int chunk = 0; chunk < num_chunks; chunk++) {
        int elements_in_chunk = count_chunk(stackA, *sizeA, current_min, current_max);
        while (elements_in_chunk-- > 0) {
            // Encuentra el elemento más cercano al top en el chunk actual
            closest = find_closest_in_range(stackA, *sizeA, current_min, current_max);
            rotate_to_top(stackA, sizeA, closest);
            op_pb(stackA, sizeA, stackB, sizeB);
            if (*sizeB > 1 && stackB[0] < stackB[1]) {
                op_rb(stackB, sizeB);  // Mantiene B ordenado descendentemente
            }
        }
        current_max = current_min - 1;
        current_min = current_max - chunk_size + 1;
    }
}

