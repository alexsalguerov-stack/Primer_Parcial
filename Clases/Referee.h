#pragma once
#include <vector>
#include <string>
#include "Robot.h"

using namespace std;

// Clase Referee: Responsable de resolver los enfrentamientos de forma aleatoria.
class Referee {
public:
    Referee();

    // Selecciona dos robots al azar y devuelve el índice del ganador
    int simularBatalla(const vector<Robot>& robots);
};
