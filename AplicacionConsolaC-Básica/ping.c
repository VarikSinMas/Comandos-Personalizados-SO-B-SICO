#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS // Desactiva las advertencias relacionadas con funciones "inseguras"

// Función para realizar el ping a una dirección IP y determinar si responde
int ping(const char* ip) {
    // Construir el comando de ping
    char comando[100];
    sprintf_s(comando, sizeof(comando), "ping -c 1 %s", ip); // Corregir aquí

    // Ejecutar el comando de ping y capturar el resultado
    int resultado = system(comando);

    // Determinar si el resultado indica que la dirección IP respondió
    if (resultado == 0) {
        printf("La direccion IP %s respondio positivamente.\n", ip);
        return 1;  // Devuelve 1 si la dirección IP respondió
    }
    else {
        printf("La direccion IP %s no respondio.\n", ip);
        return 0;  // Devuelve 0 si la dirección IP no respondió
    }
}

// Función para leer las direcciones IP desde un archivo de texto y realizar el ping a cada una
void pingDirecciones(const char* nombreArchivo) {
    FILE* archivo;
    errno_t err = fopen_s(&archivo, nombreArchivo, "r");
    if (err != 0 || archivo == NULL) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return;
    }

    char ip[20];
    unsigned int tamanoBuffer = sizeof(ip); // Convertir el tamaño del buffer a unsigned int
    while (fscanf_s(archivo, "%19s", ip, tamanoBuffer) != EOF) {
        ping(ip);
    }

    fclose(archivo);
}
