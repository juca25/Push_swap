/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:52:07 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 16:42:39 by juan-ser         ###   ########.fr       */
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
long long int	ft_partition(int arr[], int low, int high);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	ft_error(void);
void	free_index(char **index, int n);



void	ft_print_stack(int *stack, int size);
void	ft_print_stack_hex(int *stack, int size);

void    ft_qsort(int arr[], int low, int high);
void    bubble_sort(int *arr, int n);
char    **ft_assign_index_hex(int original[], int n);
int     get_max(int *stack, int size);
int     get_digits(int max);
int     get_max_len(char **stack, int size);
int     *normalize(int *arr, int a);
void	parse_and_validate(int argc, char **argv, int **arr, int *n);

void op_pb(int *stackA, int *sizeA, int *stackB, int *sizeB);
void op_pa(int *stackA, int *sizeA, int *stackB, int *sizeB);
void op_ra(int *stackA, int *sizeA);
void op_rb(int *stackB, int *sizeB);
void op_rrb(int *stackB, int *sizeB);
void op_rr(int *stackA, int *sizeA, int *stackB, int *sizeB);
void rotate_to_top(int *stack, int *size, int value, char name);
void op_rra(int *stackA, int *sizeA);


int find_position(int *stack, int size, int value);
void push_back(int *stackA, int *sizeA, int *stackB, int *sizeB);
int find_max_index(int *stack, int size);
void chunk_sort(int *stackA, int *sizeA, int *stackB, int *sizeB);
