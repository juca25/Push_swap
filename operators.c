/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 16:37:47 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/20 16:37:47 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_ra(int *stack, int *size) {
    int temp, i;
    if (*size < 2)
        return;
    temp = stack[0];
    i = 0;
    while (i < *size - 1) {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[*size - 1] = temp;
    printf("ra\n");
}

void op_rra(int *stack, int *size) {
    int temp, i;
    if (*size < 2)
        return;
    temp = stack[*size - 1];
    i = *size - 1;
    while (i > 0) {
        stack[i] = stack[i - 1];
        i--;
    }
    stack[0] = temp;
    printf("rra\n");
}

void op_pb(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    int value, i;
    if (*sizeA <= 0)
        return;
    value = stackA[0];
    i = 0;
    while (i < *sizeA - 1) {
        stackA[i] = stackA[i + 1];
        i++;
    }
    (*sizeA)--;
    i = *sizeB;
    while (i > 0) {
        stackB[i] = stackB[i - 1];
        i--;
    }
    stackB[0] = value;
    (*sizeB)++;
    printf("pb\n");
}

void op_pa(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    int value, i;
    if (*sizeB <= 0)
        return;
    value = stackB[0];
    i = 0;
    while (i < *sizeB - 1) {
        stackB[i] = stackB[i + 1];
        i++;
    }
    (*sizeB)--;
    i = *sizeA;
    while (i > 0) {
        stackA[i] = stackA[i - 1];
        i--;
    }
    stackA[0] = value;
    (*sizeA)++;
    printf("pa\n");
}

void op_rb(int *stackB, int *sizeB) {
    int temp, i;
    if (*sizeB < 2)
        return;
    temp = stackB[0];
    i = 0;
    while (i < *sizeB - 1) {
        stackB[i] = stackB[i + 1];
        i++;
    }
    stackB[*sizeB - 1] = temp;
    printf("rb\n");
}

void op_rrb(int *stackB, int *sizeB) {
    int temp, i;
    if (*sizeB < 2)
        return;
    temp = stackB[*sizeB - 1];
    i = *sizeB - 1;
    while (i > 0) {
        stackB[i] = stackB[i - 1];
        i--;
    }
    stackB[0] = temp;
    printf("rrb\n");
}