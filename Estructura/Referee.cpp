#include "../Clases/Referee.h"
#include <random>
#include <stdexcept>

using namespace std;

// Constructor de Referee
Referee::Referee() {}

// Simula una batalla seleccionando dos robots al azar y determinando un ganador
int Referee::simularBatalla(const vector<Robot>& robots) {
    if (robots.size() < 2) {
        throw invalid_argument("Se necesitan al menos 2 robots para simular una batalla.");
    }

    // Generador moderno de números aleatorios (estático para no reiniciarse en cada llamada)
    static random_device rd;
    static mt19937 gen(rd());

    // Distribución para elegir índices válidos del vector de robots
    uniform_int_distribution<size_t> distIndice(0, robots.size() - 1);

    // 1. Elegir dos índices distintos
    size_t idx1 = distIndice(gen);
    size_t idx2 = distIndice(gen);
    while (idx2 == idx1) {
        idx2 = distIndice(gen);
    }

    // 2. Determinar el ganador (50/50)
    uniform_int_distribution<int> monedaDist(0, 1);
    int moneda = monedaDist(gen);

    // Devolvemos el índice del ganador
    return (moneda == 0) ? static_cast<int>(idx1) : static_cast<int>(idx2);
}
