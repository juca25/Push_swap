/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:56:26 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 12:56:26 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_back(int *stackA, int *sizeA, int *stackB, int *sizeB) {
    while (*sizeB > 0) {
        op_pa(stackA, sizeA, stackB, sizeB);
        if (*sizeB > 0 && stackB[0] > stackA[0]) op_ra(stackA, sizeA);
    }
}