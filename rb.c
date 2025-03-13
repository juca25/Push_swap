/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:42:19 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 12:42:19 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_rb(int *stackB, int *sizeB)
{
    int temp = stackB[0], i = 0;
    while(i < *sizeB - 1)
    {
        stackB[i] = stackB[i+1];
        i++;
    }
    stackB[*sizeB - 1] = temp;
    printf("rb\n");
}