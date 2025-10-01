// Clase que controla la lógica del juego usando un puntero a Tablero
class Juego {
private:
    Tablero* tablero; // puntero dinámico a un objeto Tablero
    char jugadores[2]; // símbolos de los jugadores: X y O
    int turnoIndice;   // 0 o 1 para saber quién juega
    char* turnoPtr;    // puntero al símbolo del jugador actual

public:
    // Constructor: crea el tablero en memoria dinámica y prepara jugadores
    Juego() {
        tablero = new Tablero(); // reservar tablero con new
        jugadores[0] = 'X';
        jugadores[1] = 'O';
        turnoIndice = 0; // empieza jugador 0 (X)
        turnoPtr = &jugadores[turnoIndice]; // puntero al símbolo actual
    }

    // Destructor: liberar el tablero
    ~Juego() {
        delete tablero; // llamar al destructor de Tablero
    }

    // Cambiar el turno actual (y actualizar puntero)
    void cambiarTurno() {
        turnoIndice = (turnoIndice + 1) % 2;
        turnoPtr = &jugadores[turnoIndice];
    }

    // Método que ejecuta el bucle principal del juego
    void jugar() {
        int fila, col;
        char ganador = ' ';

        // mientras no haya ganador y el tablero no esté lleno
        while (ganador == ' ' && !tablero->tableroLleno()) {
            // mostrar el tablero (nota: usamos '->' porque tablero es puntero)
            tablero->mostrar();

            // mostrar el turno usando el puntero turnoPtr
            cout << "Turno del jugador " << *turnoPtr << endl;
            cout << "Ingresa fila y columna (ejemplo: 1 2): ";

            // leer entrada y validar
            if (!(cin >> fila >> col)) {
                // si la entrada no es numérica, limpiar cin y descartar línea
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Por favor escribe dos números (fila columna).\n";
                continue;
            }

            // intentar colocar la ficha usando el símbolo apuntado por turnoPtr
            if (!tablero->colocarFicha(fila, col, *turnoPtr)) {
                cout << "Movimiento inválido (fuera de rango o celda ocupada). Intenta de nuevo.\n\n";
                continue; // pedir otra entrada al mismo jugador
            }

            // después del movimiento, comprobar si hay ganador
            ganador = tablero->verificarGanador();
            if (ganador != ' ') break; // si hay ganador, salir del bucle

            // cambiar turno para el siguiente movimiento
            cambiarTurno();
        }

        // mostrar tablero final
        tablero->mostrar();

        // resultado final
        if (ganador != ' ')
            cout << "¡El jugador " << ganador << " ha ganado! Felicidades.\n";
        else
            cout << "¡Empate! No hay más movimientos posibles.\n";
    }
};