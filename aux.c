/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:49:03 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/21 16:57:33 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(const char *str) {
    int sign = 1, i = 0;
    long res = 0;
    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') sign = -1;
        i++;
    }
    if (!str[i]) { write(2, "Error\n", 6); exit(1); }
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9') { write(2, "Error\n", 6); exit(1); }
        res = res * 10 + (str[i] - '0');
        if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN)) {
            write(2, "Error\n", 6); exit(1);
        }
        i++;
    }
    return (int)(res * sign);
}
