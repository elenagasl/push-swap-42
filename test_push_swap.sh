#!/bin/bash

# Generar números únicos entre -1000 y 1000 con awk
ARG=$(awk -v min=-2147483648 -v max=2147483647 -v n=500 'BEGIN {
    srand();
    while (count < n) {
        r = int(min + rand() * (max - min + 1));
        if (!(r in seen)) {
            seen[r] = 1;
            printf "%d ", r;
            count++;
        }
    }
}')

# Ejecutar push_swap y guardar los movimientos
MOVES=$(./push_swap $ARG)

# Contar número de líneas (movimientos)
NUM_LINES=$(echo "$MOVES" | wc -l)
echo "Número de movimientos: $NUM_LINES"

# Comprobar con checker
echo "$MOVES" | ./checker_Mac $ARG
