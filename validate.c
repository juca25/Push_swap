/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:25:58 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/21 16:40:26 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parse_and_validate(int argc, char **argv, int **arr, int *n) {
    int i, j;
    *n = argc - 1;
    if (*n <= 0)
        ft_error();
    *arr = malloc(sizeof(int) * (*n));
    if (!*arr)
        ft_error();
    for (i = 1; i < argc; i++)
        (*arr)[i - 1] = ft_atoi(argv[i]);
    for (i = 0; i < *n; i++) {
        for (j = i + 1; j < *n; j++) {
            if ((*arr)[i] == (*arr)[j])
                ft_error();
        }
    }
}