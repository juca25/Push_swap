/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:52:07 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/07 13:09:23 by juan-ser         ###   ########.fr       */
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

void op_pb(char **stackA, int *sizeA, char **stackB, int *sizeB);
void op_pa(char **stackA, int *sizeA, char **stackB, int *sizeB);
void op_ra(char **stack, int *size);
void rotate_no_print(char **stack, int *size);

void	ft_print_stack(int *stack, int size);
void	ft_print_stack_hex(int *stack, int size);

void    ft_qsort(int arr[], int low, int high);
char    **ft_assign_index_hex(int original[], int n);
void    bubble_sort(int *arr, int n);
int     get_max(int *stack, int size);
int     get_digits(int max);
int     get_max_len(char **stack, int size);
int     *normalize(int *arr, int a);
void radix_sort_hex_str(char **stackA, char **stackB, int *sizes, int max_len);
void    parse_and_validate(int	argc, char **argv, int **arr, int *n);