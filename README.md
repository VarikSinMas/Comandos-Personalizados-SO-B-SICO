# Comandos-Personalizados-SO-BÁSICO

Descripción 
Dado que ya estás preparado para crear aplicaciones de consola escritas en C usando Visual Studio, en este producto desarrollarás una aplicación en c, la funcionalidad de la cual es que adquieras destrezas en lo referente a editar archivos de texto.

Objetivos
El objetivo principal del producto es:
Desarrollar una pequeña aplicación escrita en C.
Adquirir las destrezas necesarias en lo referente a la edición de archivos de texto y en el lanzamiento y control desde una aplicación de comandos simples de la consola de Windows.

Pasos a seguir 
Los pasos a seguir para llevar a cabo el producto son:

Realizar una pequeña aplicación de consola escrita en C que implementará las siguientes funcionalidades. 
Mostrar inicialmente un menú que permita seleccionar a cuál de las diferentes funcionalidades implementadas en la aplicación se va a acceder y que serán las siguientes:
Insertar la fecha y la hora en el documento de salida: producto2.txt (Especificar en la memoria donde se genera dicho archivo)
Comprobar e informar por pantalla sobre cuáles de una lista de máquinas referenciadas por su IP escrita en un archivo de texto, contestan positivamente a un ping lanzado por la aplicación que estás programando. Se recomienda generar un submenú donde se solicite el nombre y ubicación de dicho archivo.
Mostrar y guardar en un fichero llamado adaptador.txt, la configuración de red de la máquina local para un adaptador que previamente se preguntará al usuario. 

Insertar la fecha y la hora en el documento de salida: producto2.txt (Especificar en la memoria donde se genera dicho archivo) (Menú punto 1)
 
Diseñar una función que lea el contenido de un archivo de texto que consiste en una serie de direcciones IP cada una de las cuales ocupa una línea de éste. La ruta y nombre del archivo de texto se preguntarán al usuario e inicialmente se mostrará el contenido de este por pantalla. Finalmente lanzará un ping para cada una de las IP’s y determinará e informará sobre cuáles de las anteriores responden afirmativamente a este comando. (Menú punto 2)

Se almacenará el resultado del paso anterior debajo de la fecha y la hora en el archivo producto2.txt, las IPs que han dado una respuesta positiva. Guardar el archivo y no borrar. (Menú punto 2)
Diseñar una función cuya funcionalidad que muestre los adaptadores de red de la máquina local. Se mostrará y almacenará en un archivo adaptador.txt la información para un adaptador de red; él cual, se preguntará previamente al usuario (elegido por el usuario) su IP, máscara, y puerta de enlace. El resto de configuraciones de red no se han de mostrar esta información. Para realizar lo anterior la función lanzará un comando de dos que le proporcionará la información que necesita junto con otra que no se considera relevante, y será capaz de extraer y mostrar la que se ha detallado. (menú punto3)
Realizar la aplicación modularizada, al menos ha de contar con las funciones descritas en los puntos anteriores, con su código bien comentado. Haz uso de todos los archivos temporales que requieras.
