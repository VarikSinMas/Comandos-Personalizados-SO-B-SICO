#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS // Desactiva las advertencias relacionadas con funciones "inseguras"

// Funci�n para realizar el ping a una direcci�n IP y determinar si responde
int ping(const char* ip) {
    // Construir el comando de ping
    char comando[100];
    sprintf_s(comando, sizeof(comando), "ping -c 1 %s", ip); // Corregir aqu�

    // Ejecutar el comando de ping y capturar el resultado
    int resultado = system(comando);

    // Determinar si el resultado indica que la direcci�n IP respondi�
    if (resultado == 0) {
        printf("La direccion IP %s respondio positivamente.\n", ip);
        return 1;  // Devuelve 1 si la direcci�n IP respondi�
    }
    else {
        printf("La direccion IP %s no respondio.\n", ip);
        return 0;  // Devuelve 0 si la direcci�n IP no respondi�
    }
}

// Funci�n para leer las direcciones IP desde un archivo de texto y realizar el ping a cada una
void pingDirecciones(const char* nombreArchivo) {
    FILE* archivo;
    errno_t err = fopen_s(&archivo, nombreArchivo, "r");
    if (err != 0 || archivo == NULL) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return;
    }

    char ip[20];
    unsigned int tamanoBuffer = sizeof(ip); // Convertir el tama�o del buffer a unsigned int
    while (fscanf_s(archivo, "%19s", ip, tamanoBuffer) != EOF) {
        ping(ip);
    }

    fclose(archivo);
}
