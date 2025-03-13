/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:25:58 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/12 16:25:10 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(char *str)
{
	int i = 0;

	if (str[i] == '-' || str[i] == '+') // Permite signos al inicio
		i++;
	if (!str[i]) // Debe haber al menos un dígito después del signo
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i])) // Si encuentra algo que no es número
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str) // Versión de atoi con control de overflow
{
	long	result = 0;
	int		sign = 1;
	int		i = 0;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX) || (sign == -1 && -result < INT_MIN))
			ft_error(); // Si se sale del rango de int, error
		i++;
	}
	return (result * sign);
}

void	parse_and_validate(int argc, char **argv, int **arr, int *n)
{
	int i, j;
	*n = argc - 1;
	if (*n <= 0)
		ft_error(); // Si no hay números, error

	*arr = (int *)malloc(sizeof(int) * (*n));
	if (!*arr)
		ft_error();

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i])) // Verifica si es un número válido
			ft_error();
		(*arr)[i - 1] = (int)ft_atol(argv[i]); // Usa atol para evitar overflow
		i++;
	}

	// Comprobación de duplicados
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