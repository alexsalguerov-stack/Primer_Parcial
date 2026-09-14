#pragma once
#include <vector>
#include <string>
#include "Equipo.h"
#include "Robot.h"

// Clase Organizador: Gestiona el registro de equipos y la coordinación de la competencia.
class Organizador {
private:
    std::vector<Equipo> equipos;

    // Método auxiliar interno para agrupar robots por disciplina
    std::vector<Robot> filtrarPorTipo(const std::vector<Robot>& robots, const std::string& tipo) const;

public:
    Organizador();

    // Proceso de captura de datos (encapsulado)
    void ejecutarRegistro();

    // Getters para la capa de presentación
    std::vector<std::string> getNombresEquipos() const;
    std::vector<std::pair<std::string, std::string>> getEmparejamientos(const std::string& disciplina) const;

    // Coordina la simulación de batallas usando un Referee
    std::vector<std::string> obtenerGanadores(class Referee& ref);
};
