/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:25:58 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/07 12:26:46 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parse_and_validate(int argc, char **argv, int **arr, int *n)
{
	int i, j;
	*n = argc - 1;
	*arr = (int *)malloc(sizeof(int) * (*n));
	if (!*arr)
		ft_error();
	i = 1;
	while (i < argc)
	{
		(*arr)[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < *n)
	{
		j = i + 1;
		while (j < *n)
		{
			if ((*arr)[i] == (*arr)[j])
				ft_error();
			j++;
		}
		i++;
	}
}