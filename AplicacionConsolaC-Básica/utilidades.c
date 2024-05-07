#include <stdio.h>

// Funci�n para imprimir un men�
void imprimirMenu() {
    printf("Menu:\n");
    printf("1. Insertar fecha y hora en producto2.txt\n");
    printf("2. Comprobar y listar maquinas que responden a ping\n");
    printf("3. Mostrar y guardar configuracion de adaptador de red\n");
    printf("4. Salir\n");
}

// Funci�n para leer un archivo de texto y mostrar su contenido
void mostrarContenidoArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return;
    }

    char linea[100];
    printf("Contenido del archivo %s:\n", nombreArchivo);
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }

    fclose(archivo);
}
