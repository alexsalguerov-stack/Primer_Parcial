#include "Organizador.h"
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
