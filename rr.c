/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:16:31 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 16:16:31 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void op_rr(int *stackA, int *sizeA, int *stackB, int *sizeB) 
{
    op_ra(stackA, sizeA);
    op_rb(stackB, sizeB);
    printf("rr\n");
}