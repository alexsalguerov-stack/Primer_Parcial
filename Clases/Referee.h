#pragma once
#include <vector>
#include <string>
#include "Robot.h"

// Tema 7: dado un vector<Robot> con al menos 2 elementos,
// selecciona dos robots distintos al azar y devuelve el indice del ganador
// (indice dentro del vector original 'robots').
// Usa <random> (mt19937), no rand().
int simularBatalla(const std::vector<Robot>& robots);

