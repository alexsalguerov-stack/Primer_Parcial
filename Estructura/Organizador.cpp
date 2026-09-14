#include "Organizador.h"
#include "Referee.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor de Organizador
Organizador::Organizador() {}

// Método para capturar la entrada de datos del usuario
void Organizador::ejecutarRegistro() {
    int numEquipos;
    cout << "Ingrese la cantidad de equipos a registrar: ";
    cin >> numEquipos;

    for (int i = 0; i < numEquipos; ++i) {
        string nombreEq;
        cout << "\n--- Registro Equipo " << (i + 1) << " ---\n";
        cout << "Nombre del Equipo: ";
        cin.ignore();
        getline(cin, nombreEq);

        Equipo equipo(nombreEq);

        // Registro de integrantes
        int numInt;
        cout << "Cantidad de integrantes: ";
        cin >> numInt;
        for (int j = 0; j < numInt; ++j) {
            string nomInt, rolInt;
            cout << "  Nombre integrante " << (j + 1) << ": ";
            cin.ignore();
            getline(cin, nomInt);
            cout << "  Rol (Analista/Programador/Tester): ";
            getline(cin, rolInt);
            equipo.agregarIntegrante(Integrante(nomInt, rolInt));
        }

        // Registro de robots
        int numRob;
        cout << "Cantidad de robots: ";
        cin >> numRob;
        for (int k = 0; k < numRob; ++k) {
            string nomRob, tipoRob;
            cout << "  Nombre robot " << (k + 1) << ": ";
            cin.ignore();
            getline(cin, nomRob);
            cout << "  Tipo (Sumo/Seguidor de linea/Combate): ";
            getline(cin, tipoRob);
            equipo.agregarRobot(Robot(nomRob, tipoRob));
        }

        equipos.push_back(equipo);
    }
}

// Devuelve la lista de nombres de los equipos registrados
vector<string> Organizador::getNombresEquipos() const {
    vector<string> nombres;
    for (const auto& eq : equipos) {
        nombres.push_back(eq.getNombreEquipo());
    }
    return nombres;
}

// Filtra robots por disciplina (Método Auxiliar)
vector<Robot> Organizador::filtrarPorTipo(const vector<Robot>& robots, const string& tipo) const {
    vector<Robot> resultado;
    for (const auto& r : robots) {
        if (r.getTipo() == tipo) {
            resultado.push_back(r);
        }
    }
    return resultado;
}

// Genera los emparejamientos para una disciplina específica
vector<pair<string, string>> Organizador::getEmparejamientos(const string& disciplina) const {
    // Primero reunimos todos los robots de esa disciplina de todos los equipos
    vector<Robot> todosLosRobots;
    for (const auto& eq : equipos) {
        for (const auto& r : eq.getRobots()) {
            if (r.getTipo() == disciplina) {
                todosLosRobots.push_back(r);
            }
        }
    }

    vector<pair<string, string>> pares;
    // Emparejamos de dos en dos
    for (size_t i = 0; i + 1 < todosLosRobots.size(); i += 2) {
        pares.push_back({todosLosRobots[i].getNombre(), todosLosRobots[i + 1].getNombre()});
    }

    return pares;
}

// Coordina la simulación de batallas hasta encontrar un ganador por disciplina
vector<string> Organizador::obtenerGanadores(Referee& ref) {
    vector<string> ganadoresFinales;
    vector<string> disciplinas = {"Sumo", "Seguidor de linea", "Combate"};

    for (const string& disc : disciplinas) {
        vector<Robot> concursantes;
        for (const auto& eq : equipos) {
            for (const auto& r : eq.getRobots()) {
                if (r.getTipo() == disc) {
                    concursantes.push_back(r);
                }
            }
        }

        if (concursantes.empty()) continue;

        // Simular eliminatorias hasta que quede solo uno
        while (concursantes.size() > 1) {
            int winnerIdx = ref.simularBatalla(concursantes);

            // Guardamos el ganador y limpiamos el vector para la siguiente ronda
            // Para simplificar: el ganador pasa a la siguiente ronda, los demás se eliminan
            // En una competencia real sería un torneo, aquí hacemos una eliminación rápida
            Robot winner = concursantes[winnerIdx];
            concursantes.clear();
            concursantes.push_back(winner);
        }

        ganadoresFinales.push_back(concursantes[0].getNombre() + " (" + disc + ")");
    }

    return ganadoresFinales;
}
