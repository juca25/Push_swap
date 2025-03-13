/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:41:02 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 13:40:44 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_ra(int *stackA, int *sizeA)
{
    int temp = stackA[0], i = 0;
    while(i < *sizeA - 1)
    {
        stackA[i] = stackA[i+1];
        i++;
    }
    stackA[*sizeA - 1] = temp;
    printf("ra\n");
}