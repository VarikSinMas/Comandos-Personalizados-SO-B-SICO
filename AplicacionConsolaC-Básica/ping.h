#ifndef PING_H
#define PING_H

// Prototipo de la funci�n para realizar el ping a una direcci�n IP y determinar si responde
int ping(const char* ip);

// Prototipo de la funci�n para leer las direcciones IP desde un archivo de texto y realizar el ping a cada una
void pingDirecciones(const char* nombreArchivo);

#endif // PING_H
