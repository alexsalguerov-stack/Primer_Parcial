#include "Referee.h"
#include <random>
#include <stdexcept>

using namespace std;

int simularBatalla(const vector<Robot>& robots) {
    if (robots.size() < 2) {
        throw invalid_argument("Se necesitan al menos 2 robots para simular una batalla.");
    }
    
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<size_t> distIndice(0, robots.size() - 1);
    
    size_t idx1 = distIndice(gen);  // ← FALTA ESTO
    size_t idx2 = distIndice(gen);  // ← FALTA ESTO
    
    uniform_int_distribution<int> monedaDist(0, 1);
    int moneda = monedaDist(gen);
    
    return (moneda == 0) ? static_cast<int>(idx1) : static_cast<int>(idx2);
}
