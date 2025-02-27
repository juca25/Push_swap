/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:52:07 by juan-ser          #+#    #+#             */
/*   Updated: 2025/02/27 11:55:53 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

typedef struct s_node {
	int value;
	int index;
	struct s_node *next;
} t_node;
