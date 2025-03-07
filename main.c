/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:51:20 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/07 13:19:58 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int n = ac - 1, i;
	int *arr = malloc(n * sizeof(int));
	if (!arr)
		ft_error();
	i = 0;
	while (i < n)
	{
		arr[i] = atoi(av[i + 1]);
		i++;
	}
	/* Obtiene los índices en hexadecimal */
	char **stackA = ft_assign_index_hex(arr, n);
	char **stackB = malloc(n * sizeof(char *));
	if (!stackB)
		ft_error();
	/* sizes[0] = tamaño de A, sizes[1] = tamaño de B */
	int sizes[2] = { n, 0 };
	int max_len = get_max_len(stackA, sizes[0]);
	radix_sort_hex_str(stackA, stackB, sizes, max_len);
	/* No se imprime el resultado final, solo las instrucciones */
	free(arr);
	free(stackA);
	free(stackB);
	return 0;
}