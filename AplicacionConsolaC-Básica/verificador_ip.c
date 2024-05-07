#include "verificador_ip.h"
#include "ping.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Función para verificar si una cadena representa una dirección IP válida
int esDireccionIPValida(const char* direccionIP) {
    // Contadores para el número de puntos y el número de dígitos en cada octeto
    int puntos = 0;
    int digitosEnOcteto = 0;

    // Iterar sobre cada carácter de la cadena de la dirección IP
    while (*direccionIP) {
        // Si el carácter actual es un dígito
        if (isdigit(*direccionIP)) {
            // Incrementar el contador de dígitos en el octeto actual
            digitosEnOcteto++;

            // Verificar si hay más de 3 dígitos en el octeto
            if (digitosEnOcteto > 3) {
                return 0; // Si hay más de 3 dígitos, la dirección IP es inválida
            }

            // Convertir el carácter a entero y verificar si está en el rango correcto (0-9)
            int valor = *direccionIP - '0';
            if (valor < 0 || valor > 9) {
                return 0; // Si el valor está fuera del rango, la dirección IP es inválida
            }
        }
        // Si el carácter actual es un punto
        else if (*direccionIP == '.') {
            // Incrementar el contador de puntos
            puntos++;

            // Verificar si hay más de 3 dígitos en el octeto actual
            if (digitosEnOcteto == 0 || digitosEnOcteto > 3) {
                return 0; // Si no hay dígitos en el octeto o más de 3, la dirección IP es inválida
            }

            // Reiniciar el contador de dígitos en el octeto para el próximo octeto
            digitosEnOcteto = 0;
        }
        // Si el carácter no es un dígito ni un punto, la dirección IP es inválida
        else {
            return 0;
        }

        // Mover al siguiente carácter de la dirección IP
        direccionIP++;
    }

    // Verificar si la dirección IP tiene exactamente 3 puntos y 4 octetos
    if (puntos != 3 || digitosEnOcteto == 0 || digitosEnOcteto > 3) {
        return 0;
    }

    // La dirección IP es válida
    return 1;
}

// Función para verificar las direcciones IP en un archivo
void verificarDireccionesIP(const char* nombreArchivo) {
    FILE* archivo;
    char direccionIP[100]; // Aumentamos el tamaño del buffer para manejar direcciones IP más largas

    // Abrir el archivo de texto
    errno_t err = fopen_s(&archivo, nombreArchivo, "r");
    if (err != 0) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return;
    }

    printf("Direcciones IP que respondieron positivamente al ping:\n");
    // Leer cada dirección IP del archivo y realizar un ping
    while (fgets(direccionIP, sizeof(direccionIP), archivo) != NULL) {
        // Eliminar el salto de línea al final de la dirección IP
        direccionIP[strcspn(direccionIP, "\n")] = '\0';

        // Verificar si la dirección IP es válida
        if (esDireccionIPValida(direccionIP)) {
            // Llamar a la función ping para verificar la dirección IP
            if (ping(direccionIP)) {
                printf("%s\n", direccionIP);
            }
        }
        else {
            printf("Direccion IP no valida: %s\n", direccionIP);
        }
    }

    // Cerrar el archivo
    fclose(archivo);
}

