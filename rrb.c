/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:43:54 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 12:43:54 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_rrb(int *stackB, int *sizeB)
{
    int temp = stackB[*sizeB - 1], i = *sizeB - 1;
    while(i > 0)
    {
        stackB[i] = stackB[i-1];
        i--;
    }
    stackB[0] = temp;
    printf("rrb\n");
}