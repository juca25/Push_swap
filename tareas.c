1. Lectura y Validación de Entrada
Objetivo: Leer los argumentos pasados por línea de comandos, validarlos y convertirlos en números enteros sin duplicados.
Funciones a implementar:
ft_atoi:
Qué hace: Convierte una cadena a entero.
Uso: Se utilizará para transformar cada argumento a un número.
ft_split:
Qué hace: Divide una cadena en un array de cadenas (para separar argumentos si vienen juntos).
Uso: Si los números se pasan en una sola cadena, se usa para separarlos.
**parse_arguments(int argc, char argv):
Qué hace:
Recibe los argumentos del programa.
Usa ft_split/ft_atoi para convertirlos a enteros.
Verifica que sean números válidos y que no haya duplicados.
En caso de error, utiliza exit.
Salida: Un array (o estructura) de enteros listos para insertar en la pila A.


2. Estructuras de Datos y Manejo de Pilas
Objetivo: Definir la estructura de nodo para las pilas y las funciones básicas para manipularlas.
Funciones y estructuras a implementar:
Estructura de nodo (t_node):
c
Copiar
Editar
typedef struct s_node {
    int value;      // Valor original (después se sustituirá por índice)
    int index;      // Índice asignado (inicialmente, puede ser 0)
    struct s_node *next;
} t_node;
create_node(int value):
Qué hace: Aloca memoria para un nodo, asigna el valor y lo inicializa.
**push_node(t_node *stack, t_node new_node):
Qué hace: Inserta un nodo al principio de la pila.
**pop_node(t_node stack):
Qué hace: Extrae el nodo superior de la pila y lo retorna.
Funciones para operaciones de la pila (Push Swap):
**swap(t_node stack):
Qué hace: Intercambia los dos primeros elementos de la pila.
**push(t_node **src, t_node dest):
Qué hace: Saca el elemento superior de la pila origen y lo inserta en la pila destino.
**rotate(t_node stack):
Qué hace: Mueve el primer elemento al final de la pila.
**reverse_rotate(t_node stack):
Qué hace: Mueve el último elemento al principio de la pila.


3. Preprocesamiento: Copiar y Convertir a Índices
Objetivo: Crear una copia de la pila A, ordenarla y asignar a cada número su índice en el orden correcto.
Funciones a implementar:
**copy_stack_to_array(t_node *stack, int *array, int size):
Qué hace: Recorre la pila A, copia sus valores en un array dinámico y almacena el tamaño.
*sort_array(int array, int size):
Qué hace: Ordena el array usando un algoritmo como QuickSort (implementado manualmente).
**assign_indices(t_node stack, int sorted_array, int size):
Qué hace:
Para cada nodo de la pila A, busca su posición en el array ordenado.
Sustituye el valor original por el índice correspondiente.


4. Implementación del Algoritmo de Ordenación (Radix Sort en Hexadecimal)
Objetivo: Ordenar la pila A (ya con índices) usando Radix Sort procesado en base hexadecimal.
Funciones a implementar:
get_max_digits(int size):
Qué hace: Calcula el número de dígitos necesarios en base 16 para representar el número máximo (size - 1).
**radix_sort(t_node **a, t_node b, int max_digits):
Qué hace:
Para cada dígito (desde el menos significativo hasta el más significativo):
Recorre la pila A y, usando la fórmula
digit = (node->index / exp) % 16
(donde exp se multiplica por 16 en cada iteración),
Distribuye los nodos en 16 “buckets” virtuales. En el contexto de Push Swap, esto se traduce en usar las operaciones de push (pb, pa) y rotate (ra, rb) para mover los elementos entre la pila A y la pila B según el valor del dígito.
Recolecta los elementos de los buckets en orden (de 0 a F) para reconstruir la pila A.
Nota: Durante la ejecución de Radix Sort, registra cada operación (ej. “pb”, “ra”, etc.) en un buffer.

5. Registro y Salida de Operaciones
Objetivo: Llevar un registro de cada operación realizada durante la ordenación y luego imprimirlas.
Funciones a implementar:
*record_operation(char op):
Qué hace: Agrega la operación (cadena de caracteres) a un buffer de salida.
print_operations(void):
Qué hace: Imprime la secuencia completa de operaciones utilizando write o printf.

6. Función Principal (main)
Objetivo: Orquestar el flujo general del programa.
Pasos dentro de main:
Llamar a parse_arguments:
Validar y convertir los argumentos en un array de enteros.
Inicializar la Pila A:
Crear la pila A utilizando create_node y push_node para cada número.
Preprocesamiento:
Copiar la pila A a un array.
Ordenar el array (sort_array).
Asignar índices a la pila A (assign_indices).
Calcular el número máximo de dígitos:
Usar get_max_digits con el tamaño de la pila.
Ordenación con Radix Sort:
Inicializar la Pila B (vacía).
Llamar a radix_sort para ordenar la pila A usando las operaciones.
Imprimir operaciones:
Llamar a print_operations para mostrar la secuencia.
Liberar la memoria:
Llamar a free para todos los recursos asignados (pila, array, buffer de operaciones).

7. Utilidades Adicionales
Funciones de cadena y conversión:
Si necesitas funciones como ft_strlen o comparadores de cadenas, impleméntalas manualmente.
Gestión de errores:
Implementa funciones para imprimir mensajes de error y utilizar exit cuando sea necesario.