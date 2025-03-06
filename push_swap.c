/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:43:50 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/06 18:30:32 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parse_and_validate(int argc, char **argv, int **arr, int *n) {
    int i, j;
    *n = argc - 1;
    *arr = (int *)malloc(sizeof(int) * (*n));
    if (!*arr) { write(2, "Error\n", 6); exit(1); }
    i = 1;
    while(i < argc) {
        (*arr)[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    i = 0;
    while(i < *n) {
        j = i + 1;
        while(j < *n) {
            if((*arr)[i] == (*arr)[j]) { write(2, "Error\n", 6); exit(1); }
            j++;
        }
        i++;
    }
}

void bubble_sort(int *arr, int n) {
    int i, j, temp;
    i = 0;
    while(i < n - 1) {
        j = 0;
        while(j < n - i - 1) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            j++;
        }
        i++;
    }
}

int* normalize(int *arr, int n) {
    int *norm = (int *)malloc(sizeof(int) * n);
    if (!norm) { write(2, "Error\n", 6); exit(1); }
    int *copy = (int *)malloc(sizeof(int) * n);
    if (!copy) { free(norm); write(2, "Error\n", 6); exit(1); }
    int i = 0;
    while(i < n) { copy[i] = arr[i]; i++; }
    bubble_sort(copy, n);
    i = 0;
    while(i < n) {
        int j = 0;
        while(j < n) {
            if(arr[i] == copy[j]) { norm[i] = j; break; }
            j++;
        }
        i++;
    }
    free(copy);
    return norm;
}

void op_ra(int *stack, int *size) {
    int temp = stack[0], i = 0;
    while(i < *size - 1) { stack[i] = stack[i+1]; i++; }
    stack[*size - 1] = temp;
    printf("ra\n");
}

void op_pb(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    int value = stackA[0], i = 0;
    while(i < *sizeA - 1) { stackA[i] = stackA[i+1]; i++; }
    (*sizeA)--;
    i = *sizeB;
    while(i > 0) { stackB[i] = stackB[i-1]; i--; }
    stackB[0] = value;
    (*sizeB)++;
    printf("pb\n");
}

void op_pa(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    int value = stackB[0], i = 0;
    while(i < *sizeB - 1) { stackB[i] = stackB[i+1]; i++; }
    (*sizeB)--;
    i = *sizeA;
    while(i > 0) { stackA[i] = stackA[i-1]; i--; }
    stackA[0] = value;
    (*sizeA)++;
    printf("pa\n");
}

int get_max(int *stack, int size) {
    int max, i;
    max = stack[0];
    i = 1;
    while(i < size) { if(stack[i] > max) max = stack[i]; i++; }
    return max;
}

int get_digits(int max) {
    int digits = 0, exp = 1;
    while(max / exp > 0) { digits++; exp *= 16; }
    return digits;
}

void radix_sort_hex(int *stackA, int *sizeA, int *stackB, int *sizeB, int digits) {
    int exp = 1, d = 0;
    while(d < digits) {
        int bucket = 15;
        while(bucket >= 0) {
            int count = *sizeA, processed = 0;
            while(processed < count) {
                int current = stackA[0];
                int digit_val = (current / exp) % 16;
                if(digit_val == bucket)
                    op_pb(stackA, sizeA, stackB, sizeB);
                else
                    op_ra(stackA, sizeA);
                processed++;
            }
            while(*sizeB > 0) { op_pa(stackA, sizeA, stackB, sizeB); }
            bucket--;
        }
        exp *= 16;
        d++;
    }
}

int main(int argc, char **argv) {
    int *arr, n;
    if(argc < 2) return 0;
    parse_and_validate(argc, argv, &arr, &n);
    int *norm = normalize(arr, n);
    free(arr);
    int *stackA = norm;
    int *stackB = (int *)malloc(sizeof(int) * n);
    if(!stackB) { write(2, "Error\n", 6); exit(1); }
    int sizeA = n, sizeB = 0;
    int max = get_max(stackA, sizeA);
    int digits = get_digits(max);
    radix_sort_hex(stackA, &sizeA, stackB, &sizeB, digits);
    free(stackB);
    free(norm);
    return 0;
}