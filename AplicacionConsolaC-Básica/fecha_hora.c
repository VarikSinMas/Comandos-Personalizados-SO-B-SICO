#include <stdio.h>
#include <time.h>
#include "fecha_hora.h"

// Función para obtener la fecha y hora actual del sistema
void obtenerFechaHora(char* buffer, int tamano) {
    time_t tiempoActual;
    struct tm infoTiempo;
    time(&tiempoActual);
    localtime_s(&infoTiempo, &tiempoActual); 
    strftime(buffer, tamano, "%Y-%m-%d %H:%M:%S", &infoTiempo); 
}

/* // Función para insertar la fecha y hora en el archivo producto2.txt abriendo el archivo en modo append "a", agregando el contenido al final
void insertarFechaHoraEnArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return;
    }

    char buffer[100];  // Tamaño suficiente para almacenar la fecha y hora
    obtenerFechaHora(buffer, sizeof(buffer));
    fprintf(archivo, "Fecha y hora: %s\n", buffer);

    fclose(archivo);
}
*/

// Función para insertar la fecha y hora en el archivo producto2.txt abriendo el archivo en  modo write "w" actualizando dicho contenido en vez de escribirlo además del anterior
void insertarFechaHoraEnArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return;
    }

    char buffer[100];  // Tamaño suficiente para almacenar la fecha y hora
    obtenerFechaHora(buffer, sizeof(buffer));
    fprintf(archivo, "Fecha y hora: %s\n", buffer);

    fclose(archivo);
}
