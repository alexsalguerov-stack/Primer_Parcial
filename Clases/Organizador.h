#pragma once
#include <vector>
#include <string>
#include "Equipo.h"
#include "Robot.h"

using namespace std;

// Clase Organizador: Gestiona el registro de equipos y la coordinación de la competencia.
class Organizador {
private:
    vector<Equipo> equipos;

    // Método auxiliar interno para agrupar robots por disciplina
    vector<Robot> filtrarPorTipo(const vector<Robot>& robots, const string& tipo) const;

public:
    Organizador();

    // Proceso de captura de datos (encapsulado)
    void ejecutarRegistro();

    // Getters para la capa de presentación
    vector<string> getNombresEquipos() const;
    vector<pair<string, string>> getEmparejamientos(const string& disciplina) const;

    // Coordina la simulación de batallas usando un Referee
    vector<string> obtenerGanadores(class Referee& ref);
};
