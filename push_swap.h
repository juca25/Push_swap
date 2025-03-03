/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:52:07 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/03 16:51:59 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_SIZE 500

int		ft_atoi(const char *str);
void	ft_swap_int(int *a, int *b);
char	*ft_itoa_hex(unsigned int num);
int		ft_partition(int arr[], int low, int high);

void	push_a(int *stackA, int *sizeA, int *stackB, int *sizeB);
void	push_b(int *stackA, int *sizeA, int *stackB, int *sizeB);
void	ft_reverse_rotate(int *stack, int size);
void	ft_swap(int *stack, int size);
void	ft_rotate(int *stack, int size);


void	ft_qsort(int arr[], int low, int high);
char	**ft_assign_index_hex(int original[], int sorted[], int n);

void	ft_print_array(int arr[], int size);
void	ft_print_stack(int *stack, int size);
void	ft_print_index_hex(char **index, int n);

void	free_index(char **index, int n);

void    ft_radix_sort(int *stackA, int sizeA, int *stackB, int sizeB);
int     ft_find_max(int *stack, int size);