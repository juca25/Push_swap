/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:52:07 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/21 17:08:04 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define MAX_SIZE 500

int ft_atoi(const char *str);
void	ft_error(void);
void bubble_sort(int *arr, int n);

void op_ra(int *stack, int *size);
void op_rra(int *stack, int *size);
void op_pb(int *stackA, int *sizeA, int *stackB, int *sizeB);
void op_pa(int *stackA, int *sizeA, int *stackB, int *sizeB);
void op_rb(int *stackB, int *sizeB);
void op_rrb(int *stackB, int *sizeB);

void parse_and_validate(int argc, char **argv, int **arr, int *n);
int *normalize(int *arr, int n);
int get_max(int *stack, int size);
int count_bits(int num);
void radix_sort(int *stackA, int *sizeA, int *stackB, int *sizeB);