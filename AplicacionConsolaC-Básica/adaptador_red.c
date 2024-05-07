#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para usar malloc y free

void mostrarConfiguracionAdaptador(const char* nombreArchivo) {
    // Abrir el archivo temporal en modo escritura
    FILE* archivoTemporal = fopen("temp.txt", "w");
    if (archivoTemporal == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        return;
    }

    // Ejecutar el comando ipconfig y capturar su salida
    FILE* ipconfig = _popen("ipconfig", "r");
    if (ipconfig == NULL) {
        printf("Error al ejecutar ipconfig.\n");
        fclose(archivoTemporal);
        return;
    }

    // Variables para capturar la informacion del adaptador
    char linea[1000];
    int contador = 0;

    // Usar una cadena de caracteres dinamica para almacenar todas las lineas del adaptador seleccionado
    char* seleccionado = malloc(1); // Inicializar con tamaño 1
    seleccionado[0] = '\0'; // Terminar la cadena

    // Leer cada linea del resultado de ipconfig
    while (fgets(linea, sizeof(linea), ipconfig) != NULL) {
        // Buscar las lineas que contienen la informacion del adaptador
        if (strstr(linea, "Ethernet") || strstr(linea, "Wi-Fi")) {
            contador++;
        }
        if (contador > 0) {
            fprintf(archivoTemporal, "%s", linea);  // Escribir la linea en el archivo temporal
            // Concatenar la linea en la cadena seleccionado
            seleccionado = realloc(seleccionado, strlen(seleccionado) + strlen(linea) + 1); // Reasignar memoria
            strcat(seleccionado, linea);
        }
        if (strstr(linea, "Direccion IPv4") || strstr(linea, "Mascara de subred") || strstr(linea, "Puerta de enlace predeterminada")) {
            fprintf(archivoTemporal, "%s", linea);  // Escribir la linea en el archivo temporal
        }
        if (strstr(linea, "Conexion de red Bluetooth")) {
            contador = 0; // Restablecer el contador cuando se encuentra un nuevo adaptador
        }
    }

    // Cerrar los archivos
    fclose(ipconfig);
    fclose(archivoTemporal);

    // Si se encontraron adaptadores de red, mostrar el contenido del archivo temporal
    if (contador > 0) {
        printf("Seleccione un adaptador de red:\n");
        FILE* archivoTemporal = fopen("temp.txt", "r");
        if (archivoTemporal == NULL) {
            printf("Error al abrir el archivo temporal para lectura.\n");
            free(seleccionado); // Liberar la memoria asignada a seleccionado
            return;
        }
        int opcion;
        while (fgets(linea, sizeof(linea), archivoTemporal) != NULL) {
            printf("%s", linea);
        }
        printf("Ingrese el numero del adaptador seleccionado: ");
        scanf("%d", &opcion);

        // Volver a leer el archivo para encontrar el adaptador seleccionado
        rewind(archivoTemporal);
        int i = 1;
        while (fgets(linea, sizeof(linea), archivoTemporal) != NULL) {
            if (strstr(linea, "Ethernet") || strstr(linea, "Wi-Fi")) {
                i++;
            }
            if (i == opcion) {
                // Concatenar todas las lineas del adaptador seleccionado
                seleccionado = realloc(seleccionado, strlen(seleccionado) + strlen(linea) + 1); // Reasignar memoria
                strcat(seleccionado, linea);
                if (strstr(linea, "Conexion de red Bluetooth")) {
                    break; // Salir del bucle cuando se ha encontrado el adaptador seleccionado
                }
            }
        }
        fclose(archivoTemporal);


        // Guardar toda la informacion del adaptador seleccionado en adaptador.txt
        FILE* archivoAdaptador = fopen(nombreArchivo, "w");
        if (archivoAdaptador == NULL) {
            printf("Error al abrir el archivo %s.\n", nombreArchivo);
            free(seleccionado); // Liberar la memoria asignada a seleccionado
            return;
        }
        fprintf(archivoAdaptador, "%s", seleccionado);
        fclose(archivoAdaptador);
    }
    else {
        printf("No se encontraron adaptadores de red.\n");
        free(seleccionado); // Liberar la memoria asignada a seleccionado
    }

    // Eliminar el archivo temporal
    remove("temp.txt");
}
