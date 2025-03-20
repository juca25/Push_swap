/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:51:20 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/20 16:59:14 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(int *stack, int size) {
    int i = 0;
    printf("\nStack ordenado:\n");
    while (i < size) {
        printf("%d ", stack[i]);
        i++;
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int *arr, n, i;
    parse_and_validate(argc, argv, &arr, &n);
    int *stackA = arr;  // Usamos los valores originales
    int sizeA = n, sizeB = 0;
    int *stackB = malloc(n * sizeof(int));
    if (!stackB)
        ft_error();
    int num_chunks = (n == 100) ? 5 : (n == 500) ? 10 : 15;
    chunk_sort(stackA, &sizeA, stackB, &sizeB, n, num_chunks);
    push_back(stackA, &sizeA, stackB, &sizeB);
    print_stack(stackA, sizeA);
    free(stackB);
    free(arr);
    return 0;
}