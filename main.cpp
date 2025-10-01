#include <iostream>
#include <limits> // para limpiar la entrada si hay error
using namespace std;

// Función principal
int main() {
    // crear el juego dinámicamente (para mostrar más uso de punteros)
    Juego* partida = new Juego();

    // iniciar la partida
    partida->jugar();

    // liberar memoria del juego
    delete partida;

    return 0;
}
Si quieres, puedo:

Añadir más comentarios explicando línea por línea.

Hacer que juegue la computadora (IA sencilla).

Mejorar la validación de entradas o agregar reinicio de partida.

¿Te gustaría alguna de esas mejoras o lo dejamos así?


