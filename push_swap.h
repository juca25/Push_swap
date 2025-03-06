/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:52:07 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/06 18:13:34 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX_SIZE 500

typedef struct {
    int arr[MAX_SIZE];
    int size;
} Stack;

int		ft_atoi(const char *str);
void	ft_swap_int(int *a, int *b);
char	*ft_itoa_hex(unsigned int num);
int		ft_partition(int arr[], int low, int high);
void	*ft_memcpy(void *dest, const void *src, size_t num);

void	push_a(int *stackA, int *sizeA, int *stackB, int *sizeB);
void	push_b(int *stackA, int *sizeA, int *stackB, int *sizeB);
void	ft_reverse_rotate(int *stack, int size);
void	ft_swap(int *stack, int size);
void	ft_rotate(int *stack, int size);

void	ft_qsort(int arr[], int low, int high);
char	**ft_assign_index_hex(int original[], int n);

void	ft_print_array(int arr[], int size);
void	ft_print_stack(int *stack, int size);
void	ft_print_index_hex(char **index, int n);
void	ft_print_stack_hex(int *stack, int size);

void	free_index(char **index, int n);

void push_swap(int *stackA, int *sizeA, int *stackB);