/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:50:56 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/21 17:04:26 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void copy_array(int *src, int *dest, int size) {
    int i = 0;
    while (i < size) {
        dest[i] = src[i];
        i++;
    }
}

void bubble_sort(int *arr, int n) {
    int i = 0, j, temp;
    while (i < n - 1) {
        j = 0;
        while (j < n - i - 1) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void fill_normalized_array(int *arr, int *copy, int *norm, int size) {
    int i = 0, j;
    while (i < size) {
        j = 0;
        while (j < size) {
            if (arr[i] == copy[j]) {
                norm[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
}

int *normalize(int *arr, int n) {
    int *norm = malloc(sizeof(int) * n);
    if (!norm)
        ft_error();
    int *copy = malloc(sizeof(int) * n);
    if (!copy) { free(norm); ft_error(); }
    copy_array(arr, copy, n);
    bubble_sort(copy, n);
    fill_normalized_array(arr, copy, norm, n);
    free(copy);
    return norm;
}