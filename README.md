# cub3D

STDERR_FILENO es una macro definida en unistd.h y representa el file descriptor del stderr (salida de errores estándar).
#define STDIN_FILENO  0  // Entrada estándar (teclado)
#define STDOUT_FILENO 1  // Salida estándar (pantalla)
#define STDERR_FILENO 2  // Salida de errores (pantalla o archivo de logs)
write(STDERR_FILENO, "Error: mensaje de error\n", 25);


O_RDONLY es una flag que se usa con open() para abrir un archivo solo en modo lectura. Está definida en fcntl.h.
Esto abre "archivo.txt" en modo solo lectura.
fd = open("archivo.txt", O_RDONLY);


⚠️ Si no incluyes <fcntl.h> en tu código, O_RDONLY y STDIN_FILENO no estaran definidos y obtendrás un error de compilación.
#include <unistd.h>  // Para write(), STDERR_FILENO
#include <fcntl.h>   // Para open(), O_RDONLY


Relacion entre fixed point numbers y los numeros rgb