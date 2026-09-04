#include "UtilRobots.h"
#include <random>
#include <stdexcept>

using namespace std;

int simularBatalla(const vector<Robot>& robots) {
    if (robots.size() < 2) {
        throw invalid_argument("Se necesitan al menos 2 robots para simular una batalla.");
    }

    // Generador moderno de numeros aleatorios (mejor distribucion que rand())
    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<size_t> distIndice(0, robots.size() - 1);

    // Elegir ganador entre los dos (50/50 por ahora; cada equipo puede
    // ponderar esto mas adelante segun atributos del robot)
    uniform_int_distribution<int> monedaDist(0, 1);
    int moneda = monedaDist(gen);

    return (moneda == 0) ? static_cast<int>(idx1) : static_cast<int>(idx2);
}
