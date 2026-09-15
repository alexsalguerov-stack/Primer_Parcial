#include "../Clases/Organizador.h"
#include "../Clases/Referee.h"
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

// Constructor de Organizador
Organizador::Organizador() {}

// Método para capturar la entrada de datos del usuario
void Organizador::ejecutarRegistro() {
    int numEquipos;
    cout << "Ingrese la cantidad de equipos a registrar: ";
    if (!(cin >> numEquipos)) return;

    for (int i = 0; i < numEquipos; ++i) {
        string nombreEq;
        cout << "\n--- Registro Equipo " << (i + 1) << " ---\n";
        cout << "Nombre del Equipo: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nombreEq);

        Equipo equipo(nombreEq);

        // Registro de integrantes
        int numInt;
        cout << "Cantidad de integrantes: ";
        cin >> numInt;
        for (int j = 0; j < numInt; ++j) {
            string nomInt, rolInt;
            cout << "  Nombre integrante " << (j + 1) << ": ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    Categorias categoria = stringToCategoria(tipo);
    for (const auto& r : robots) {
        if (r.getTipoEnum() == categoria) {
            resultado.push_back(r);
        }
    }
    return resultado;
}

// Genera los emparejamientos para una disciplina específica
vector<pair<string, string>> Organizador::getEmparejamientos(const string& disciplina) const {
    vector<Robot> todosLosRobots;
    Categorias categoria = stringToCategoria(disciplina);
    for (const auto& eq : equipos) {
        for (const auto& r : eq.getRobots()) {
            if (r.getTipoEnum() == categoria) {
                todosLosRobots.push_back(r);
            }
        }
    }

    vector<pair<string, string>> pares;
    for (size_t i = 0; i + 1 < todosLosRobots.size(); i += 2) {
        pares.push_back({todosLosRobots[i].getNombre(), todosLosRobots[i + 1].getNombre()});
    }

    return pares;
}

// Coordina la simulación de batallas mediante un torneo de eliminación directa
vector<string> Organizador::obtenerGanadores(Referee& ref) {
    vector<string> ganadoresFinales;
    vector<Categorias> disciplinas = {Categorias::SUMO, Categorias::SEGUIDOR_DE_LINEA, Categorias::COMBATE};

    for (const Categorias& disc : disciplinas) {
        vector<Robot> concursantes;
        for (const auto& eq : equipos) {
            for (const auto& r : eq.getRobots()) {
                if (r.getTipoEnum() == disc) {
                    concursantes.push_back(r);
                }
            }
        }

        if (concursantes.empty()) continue;

        // Simular eliminatorias ronda por ronda
        while (concursantes.size() > 1) {
            vector<Robot> siguientesRonda;
            for (size_t i = 0; i < concursantes.size(); i += 2) {
                if (i + 1 < concursantes.size()) {
                    // Batalla entre dos robots
                    vector<Robot> pareja = {concursantes[i], concursantes[i+1]};
                    int winnerIdx = ref.simularBatalla(pareja);
                    siguientesRonda.push_back(pareja[winnerIdx]);
                } else {
                    // Robot que pasa directo si el número de concursantes es impar
                    siguientesRonda.push_back(concursantes[i]);
                }
            }
            concursantes = siguientesRonda;
        }

        ganadoresFinales.push_back(concursantes[0].getNombre() + " (" + categoriaToString(disc) + ")");
    }

    return ganadoresFinales;
}
