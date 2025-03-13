/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_no_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:23:07 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 13:09:57 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_no_print(int **stack, int *size)
{
    int *temp = stack[0];
    int i = 0;
    while (i < *size - 1)
    {
        stack[i] = stack[i + 1];
        i++;
    }
    stack[*size - 1] = temp;
}