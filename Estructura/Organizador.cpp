#include "UtilRobots.h"
#include <random>
#include <stdexcept>

using namespace std;

vector<Robot> filtrarPorTipo(const vector<Robot>& robots, const string& tipo) {
    vector<Robot> resultado;
    for (const auto& r : robots) {
        if (r.getTipo() == tipo) {
            resultado.push_back(r);
        }
    }
    return resultado;
}

int simularBatalla(const vector<Robot>& robots) {
    if (robots.size() < 2) {
        throw invalid_argument("Se necesitan al menos 2 robots para simular una batalla.");
    }

    // Generador moderno de numeros aleatorios (mejor distribucion que rand())
    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<size_t> distIndice(0, robots.size() - 1);

    // Elegir dos indices distintos
    size_t idx1 = distIndice(gen);
    size_t idx2 = distIndice(gen);
    while (idx2 == idx1) {
        idx2 = distIndice(gen);
    }

}
