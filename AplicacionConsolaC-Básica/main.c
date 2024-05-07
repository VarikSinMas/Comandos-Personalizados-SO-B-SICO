#include <stdio.h>
#include "fecha_hora.h"
#include "ping.h"
#include "utilidades.h"
#include "verificador_ip.h"

int main() {
    int opcion;
    char nombreArchivo[100];

    do {
        imprimirMenu();
        printf("Ingrese una opcion: ");
        scanf_s("%d", &opcion);

        switch (opcion) {
        case 1:
            insertarFechaHoraEnArchivo("producto2.txt");
            printf("Se ha insertado la fecha y hora en producto2.txt.\n");
            break;
        case 2:
            printf("Ingrese el nombre del archivo que contiene las direcciones IP: ");
            scanf_s("%99s", nombreArchivo, (unsigned int)sizeof(nombreArchivo)); // Conversión explícita de size_t a unsigned int
            verificarDireccionesIP(nombreArchivo); // Llamamos a la función para verificar las direcciones IP
            /* // Lógica para linkear directamente el archivo y no escribirlo manualmente
            verificarDireccionesIP(ARCHIVO_DIRECCIONES); // Utiliza el nombre del archivo predefinido
            printf("Se han verificado las direcciones IP en %s.\n", ARCHIVO_DIRECCIONES);
            */
            printf("Se han verificado las direcciones IP en %s.\n", nombreArchivo);
            break;
        case 3:
            mostrarConfiguracionAdaptador("adaptador.txt");
            printf("Se ha mostrado la configuracion del adaptador de red.\n");
            break;
        case 4:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
        }
    } while (opcion != 4);

    return 0;
}
