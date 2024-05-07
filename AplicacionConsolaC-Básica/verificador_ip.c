#include "verificador_ip.h"
#include "ping.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Funci�n para verificar si una cadena representa una direcci�n IP v�lida
int esDireccionIPValida(const char* direccionIP) {
    // Contadores para el n�mero de puntos y el n�mero de d�gitos en cada octeto
    int puntos = 0;
    int digitosEnOcteto = 0;

    // Iterar sobre cada car�cter de la cadena de la direcci�n IP
    while (*direccionIP) {
        // Si el car�cter actual es un d�gito
        if (isdigit(*direccionIP)) {
            // Incrementar el contador de d�gitos en el octeto actual
            digitosEnOcteto++;

            // Verificar si hay m�s de 3 d�gitos en el octeto
            if (digitosEnOcteto > 3) {
                return 0; // Si hay m�s de 3 d�gitos, la direcci�n IP es inv�lida
            }

            // Convertir el car�cter a entero y verificar si est� en el rango correcto (0-9)
            int valor = *direccionIP - '0';
            if (valor < 0 || valor > 9) {
                return 0; // Si el valor est� fuera del rango, la direcci�n IP es inv�lida
            }
        }
        // Si el car�cter actual es un punto
        else if (*direccionIP == '.') {
            // Incrementar el contador de puntos
            puntos++;

            // Verificar si hay m�s de 3 d�gitos en el octeto actual
            if (digitosEnOcteto == 0 || digitosEnOcteto > 3) {
                return 0; // Si no hay d�gitos en el octeto o m�s de 3, la direcci�n IP es inv�lida
            }

            // Reiniciar el contador de d�gitos en el octeto para el pr�ximo octeto
            digitosEnOcteto = 0;
        }
        // Si el car�cter no es un d�gito ni un punto, la direcci�n IP es inv�lida
        else {
            return 0;
        }

        // Mover al siguiente car�cter de la direcci�n IP
        direccionIP++;
    }

    // Verificar si la direcci�n IP tiene exactamente 3 puntos y 4 octetos
    if (puntos != 3 || digitosEnOcteto == 0 || digitosEnOcteto > 3) {
        return 0;
    }

    // La direcci�n IP es v�lida
    return 1;
}

// Funci�n para verificar las direcciones IP en un archivo
void verificarDireccionesIP(const char* nombreArchivo) {
    FILE* archivo;
    char direccionIP[100]; // Aumentamos el tama�o del buffer para manejar direcciones IP m�s largas

    // Abrir el archivo de texto
    errno_t err = fopen_s(&archivo, nombreArchivo, "r");
    if (err != 0) {
        printf("Error al abrir el archivo %s.\n", nombreArchivo);
        return;
    }

    printf("Direcciones IP que respondieron positivamente al ping:\n");
    // Leer cada direcci�n IP del archivo y realizar un ping
    while (fgets(direccionIP, sizeof(direccionIP), archivo) != NULL) {
        // Eliminar el salto de l�nea al final de la direcci�n IP
        direccionIP[strcspn(direccionIP, "\n")] = '\0';

        // Verificar si la direcci�n IP es v�lida
        if (esDireccionIPValida(direccionIP)) {
            // Llamar a la funci�n ping para verificar la direcci�n IP
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

