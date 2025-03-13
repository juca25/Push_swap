/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:51:20 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 16:48:00 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    int n, i;
    int *arr, *norm;
    
    if (ac < 2)
        return 0;
    n = ac - 1;
    arr = malloc(n * sizeof(int));
    if (!arr)
        ft_error();
    i = 0;
    while(i < n)
    {
        arr[i] = ft_atoi(av[i+1]);
        i++;
    }
    // Normaliza el array: ahora los valores estarán entre 0 y n-1
    norm = normalize(arr, n);
    
    // Usa 'norm' como stackA en chunk sort.
    int *stackA = norm;
    int sizeA = n, sizeB = 0;
    int *stackB = malloc(n * sizeof(int));
    if (!stackB)
        ft_error();
    // Ajusta el chunk según la cantidad de números
    int chunk_size = 33; // 500 números -> ~15 chunks de 33 elementos
    chunk_sort(stackA, &sizeA, stackB, &sizeB);
    push_back(stackA, &sizeA, stackB, &sizeB);
    
    free(stackB);
    free(norm);
    free(arr);
    return 0;
}