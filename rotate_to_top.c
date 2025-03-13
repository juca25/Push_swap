/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:26:59 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 16:26:59 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_to_top(int *stack, int *size, int value, char name) {
    int pos = find_position(stack, *size, value);
    int moves = (pos <= *size / 2) ? pos : pos - *size;
    
    while (moves > 0) {
        (name == 'a') ? op_ra(stack, size) : op_rb(stack, size);
        moves--;
    }
    while (moves < 0) {
        (name == 'a') ? op_rra(stack, size) : op_rrb(stack, size);
        moves++;
    }
}