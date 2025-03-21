/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:51:20 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/21 17:11:04 by juan-ser         ###   ########.fr       */
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

void print_array(int *arr, int n) {
    int i = 0;
    printf("\nStack ordenado (números originales):\n");
    while (i < n) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int *arr, n, i;
    parse_and_validate(argc, argv, &arr, &n);
    bubble_sort(arr, n);
    print_array(arr, n);
    int *norm = normalize(arr, n);
    free(arr);
    int *stackA = norm;
    int sizeA = n, sizeB = 0;
    int *stackB = malloc(n * sizeof(int));
    if (!stackB)
        ft_error();
    radix_sort(stackA, &sizeA, stackB, &sizeB);
    print_stack(stackA, sizeA);
    free(stackB);
    free(norm);
    return 0;
}


