#include "../kernel/types.h"
#include "user.h"

int main() {
    char *addr = sbrk(4096); // Reserva una página de memoria
    if (mprotect(addr, 1) < 0) {
        printf("Error en mprotect\n");
        exit(1);
    }

    printf("mprotect aplicado. Intentando escribir...\n");
    *addr = 'A'; // Esto debería causar un fallo de segmentación si mprotect funciona

    if (munprotect(addr, 1) < 0) {
        printf("Error en munprotect\n");
        exit(1);
    }

    printf("munprotect aplicado. Escribiendo en memoria...\n");
    *addr = 'A'; // Esto debería funcionar
    printf("Escritura exitosa: %c\n", *addr);

    exit(0);
}
