/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:43:50 by juan-ser          #+#    #+#             */
/*   Updated: 2025/03/03 16:49:01 by juan-ser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_find_max(int *stack, int size)
{
    int max;
    int i;
    
    max = stack[0];
    i = 1;
    while(i < size)
    {
        if(stack[i] > max)
            max = stack[i];
        i++;
    }
    return (max);
}

void    ft_radix_sort(int *stackA, int sizeA, int *stackB, int sizeB)
{
    int max;
    int max_digits;
    int digit;
    int count;
    int current_digit;
    
    if(stackA == NULL || sizeA < 2)
        return ;
    max = ft_find_max(stackA, sizeA);
    max_digits = 0;
    while(max >> (4 * max_digits))
        max_digits++;
   digit = 0;
   while(digit < max_digits)
   {
     count = sizeA;
     while(count--)
     {
        current_digit = (stackA[0] >> (4*digit)) & 0xF;
        if(current_digit < 8)
            push_b(stackA, &sizeA, stackB, &sizeB);
        else
            ft_rotate(stackA, sizeA);
     }
     while(sizeB > 0)
        push_a(stackA, &sizeA, stackB, &sizeB);
   }
}

int main(int argc, char *argv[])
{
    // Asegurarse de que haya al menos un argumento (excluyendo el nombre del programa)
    if (argc < 2)
    {
        printf("Uso: %s <números...>\n", argv[0]);
        return 1;
    }

    // Crear la pila A y la pila B
    int *stackA = malloc((argc - 1) * sizeof(int));  // Para almacenar los números
    if (stackA == NULL)
    {
        perror("Error al asignar memoria");
        return 1;
    }

    int stackB[argc - 1]; // Pila B para el radix sort
    int sizeA = argc - 1;
    int sizeB = 0;

    // Convertir los argumentos en enteros y almacenarlos en stackA
    for (int i = 1; i < argc; i++)
    {
        stackA[i - 1] = atoi(argv[i]);  // Convertir de string a int
    }

    printf("Pila original A (en hexadecimal): ");
    ft_print_stack(stackA, sizeA);

    // Ordenar usando radix sort en base hexadecimal
    ft_radix_sort(stackA, sizeA, stackB, sizeB);

    printf("Pila A después de ft_radix_sort (en hexadecimal): ");
    ft_print_stack(stackA, sizeA);

    // Liberar la memoria de stackA
    free(stackA);

    return 0;
}
