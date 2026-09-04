#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Clases/Equipo.h"
#include "Clases/Robot.h"
#include "Clases/Organizador.h"
#include "Clases/Referee.h"
#include "Clases/Integrante.h"

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
    Organizador org;
    Referee ref;

    cout << "=== Competencia de Robotica Universitaria ===\n" << endl;

    cout << "Las inscripciones estan abiertas. Todos los equipos deben registrarse en breve." << endl;
    org.iniciar_registro();

    cout << "Se cierran las inscripciones, a continuacion se mostraran los equipos registrados:" << endl;
    cout << "\n--- Equipos Registrados ---" << endl;
    vector<string> equipos = org.Datos_Equipos();
    Tabla_Equipos(equipos);

    cout << "A continuacion se mostraran los enfrentamientos de cada disciplina" << endl;
    
    cout << "\n--- Enfrentamientos de Sumo ---" << endl;
    string disciplina = "Sumo";
      vector<pair<string, string>> pares = org.getEmparejamientos(disciplina);
      Tabla_Enfrentamientos(pares, disciplina);

    cout << "\n--- Enfrentamientos de Seguidor de linea ---" << endl;
    string disciplina = "Seguidor de linea";
      vector<pair<string, string>> pares = org.getEmparejamientos(disciplina);
      Tabla_Enfrentamientos(pares, disciplina);

    cout << "\n--- Enfrentamientos de Combate ---" << endl;
    string disciplina = "Combate";
      vector<pair<string, string>> pares = org.getEmparejamientos(disciplina);
      Tabla_Enfrentamientos(pares, disciplina);

    cout << "Todas las batallas han concluido. A continuacion se muestran los ganadores de cada disciplina:" << endl;

    cout << "\n--- Resultados de las batallas ---" << endl;
    vector<string> ganadores = ref.simular_batallas(org.getRobots());
    Tabla_Ganadores(ganadores);

    cout << "\n=== Fin de la Competencia Agradecemos su Participación ===" << endl;
  }
