#include "Robot.h"

using namespace std;

// Constructor con lista de inicializacion para eficiencia
Robot::Robot(const string& nombre, const string& tipo)
    : nombre(nombre), tipo(tipo) {}

string Robot::getNombre() const {
    return nombre;
}

string Robot::getTipo() const {
    return tipo;
}

void Robot::setNombre(const string& nuevoNombre) {
    if (!nuevoNombre.empty()) {
        nombre = nuevoNombre;
    }
}

void Robot::setTipo(const string& nuevoTipo) {
    if (!nuevoTipo.empty()) {
        tipo = nuevoTipo;
    }
}
