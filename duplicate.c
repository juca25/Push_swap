/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:38:48 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/06 17:40:40 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_duplicate(int *stack, int size) {
	int i = 0;
	while (i < size) {
		int j = i + 1;
		while (j < size) {
			if (stack[i] == stack[j]) {
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}