#include <iostream>
#include <limits> // para limpiar la entrada si hay error
#include <claseJuego>
#include <claseTablero>
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


