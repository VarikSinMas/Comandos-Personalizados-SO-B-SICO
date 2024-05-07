#ifndef PING_H
#define PING_H

// Prototipo de la función para realizar el ping a una dirección IP y determinar si responde
int ping(const char* ip);

// Prototipo de la función para leer las direcciones IP desde un archivo de texto y realizar el ping a cada una
void pingDirecciones(const char* nombreArchivo);

#endif // PING_H
