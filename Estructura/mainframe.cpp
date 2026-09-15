#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "../Clases/Equipo.h"
#include "../Clases/Robot.h"
#include "../Clases/Organizador.h"
#include "../Clases/Referee.h"
#include "../Clases/Integrante.h"

using namespace std;

// Interfaz grafica simple para mostrar datos de manera mas ordenada.

// Tabla de equipos inscritos
void Tabla_Equipos(const vector<string>& nombres) {

      int ancho = 30; // Ancho de columna

      // Estructura de la tabla
      cout << "\n+ " << string(ancho, '-') << " +" << endl;
      cout << "| " << left << setw(ancho) << "EQUIPOS INSCRITOS" << " |" << endl;
      cout << "+ " << string(ancho, '-') << " +" << endl;

      for (const string& n : nombres) {
          cout << "| " << left << setw(ancho) << n << " |" << endl;
      }

      cout << "+ " << string(ancho, '-') << " +" << endl;
  }

  void Tabla_Enfrentamientos(const vector<pair<string, string>>& pares, const string& disciplina) {

      int anchoC1 = 20, anchoC2 = 20;

      cout << "\n--- Disciplina: " << disciplina << " ---" << endl;
      cout << "+" << string(anchoC1+2, '-') << "+" << string(anchoC2+2, '-') << "+" << endl;
      cout << "| " << left << setw(anchoC1) << "ROBOT 1" << " | " << left << setw(anchoC2) << "ROBOT 2" << " |" << endl;
      cout << "+" << string(anchoC1+2, '-') << "+" << string(anchoC2+2, '-') << "+" << endl;

      for (const auto& par : pares) {
          cout << "| " << left << setw(anchoC1) << par.first << " | " << left << setw(anchoC2) << par.second << " |" << endl;
      }

      cout << "+" << string(anchoC1+2, '-') << "+" << string(anchoC2+2, '-') << "+" << endl;
  }

  void Tabla_Ganadores(const vector<string>& ganadores) {

      int ancho = 40;

      cout << "\n+ " << string(ancho, '-') << " +" << endl;
      cout << "| " << left << setw(ancho) << "GANADORES DE LAS BATALLAS" << " |" << endl;
      cout << "+ " << string(ancho, '-') << " +" << endl;

      for (const string& g : ganadores) {
          cout << "| " << left << setw(ancho) << g << " |" << endl;
      }

      cout << "+ " << string(ancho, '-') << " +" << endl;
  }

int main() {
    Organizador org; // Instancia del organizador
    Referee ref;     // Instancia del referee

    cout << "=== Competencia de Robotica Universitaria ===\n" << endl;

    cout << "Las inscripciones estan abiertas. Todos los equipos deben registrarse en breve." << endl;
    org.ejecutarRegistro(); // Inicia el proceso de registro de equipos y robots por parte del organizador

    cout << "Se cierran las inscripciones, a continuacion se mostraran los equipos registrados:" << endl;

    cout << "\n--- Equipos Registrados ---" << endl;
    vector<string> equipos = org.getNombresEquipos(); // Obtiene los nombres de los equipos registrados del organizador
    Tabla_Equipos(equipos);                       // Imprime la tabla de equipos registrados

    cout << "A continuacion se mostraran los enfrentamientos de cada disciplina" << endl;

    string disciplina;
    vector<pair<string, string>> pares;

    cout << "\n--- Enfrentamientos de Sumo ---" << endl;
    disciplina = "Sumo";                                                 // Define la disciplina
    pares = org.getEmparejamientos(disciplina);                          // Obtiene los pares de enfrentamientos para la disciplina "Sumo"
    Tabla_Enfrentamientos(pares, disciplina);                            // Imprime la tabla de enfrentamientos para la disciplina "Sumo"

    cout << "\n--- Enfrentamientos de Seguidor de linea ---" << endl;
    disciplina = "Seguidor de linea";
    pares = org.getEmparejamientos(disciplina);
    Tabla_Enfrentamientos(pares, disciplina);

    cout << "\n--- Enfrentamientos de Combate ---" << endl;
    disciplina = "Combate";
    pares = org.getEmparejamientos(disciplina);
    Tabla_Enfrentamientos(pares, disciplina);

    cout << "Todas las batallas han concluido. A continuacion se muestran los ganadores de cada disciplina:" << endl;

    cout << "\n--- Resultados de las batallas ---" << endl;
    vector<string> ganadores = org.obtenerGanadores(ref);       // El organizador coordina la simulación con el referee y devuelve los ganadores
    Tabla_Ganadores(ganadores);                                 // Imprime la tabla de ganadores de las batallas

    cout << "\n=== Fin de la Competencia Agradecemos su Participación ===" << endl;
  }
