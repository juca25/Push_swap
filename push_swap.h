/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:52:07 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/03 13:42:55 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

int			ft_atoi(const char *str);
static void	ft_swap_int(int *a, int *b);
static int	ft_partition(int arr[], int low, int high);
static void	ft_qsort(int arr[], int low, int high);
static char	*ft_itoa_hex(unsigned int num);
static char	**ft_assign_index_hex(int original[], int sorted[], int n);
static void	ft_print_index_hex(char **index, int n);
static void free_index(char **index, int n);
static void ft_print_array(int arr[], int size);
