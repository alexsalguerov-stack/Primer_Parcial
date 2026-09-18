#include "../Clases/Robot.h"

using namespace std;

// Constructor con string (convierte a enum)
Robot::Robot(const string& nombre, const string& tipo)
    : nombre(nombre), tipo(stringToCategoria(tipo)) {}

// Constructor con enum
Robot::Robot(const string& nombre, Categorias tipo)
    : nombre(nombre), tipo(tipo) {}

string Robot::getNombre() const {
    return nombre;
}

string Robot::getTipo() const {
    return categoriaToString(tipo);
}

Categorias Robot::getTipoEnum() const {
    return tipo;
}

void Robot::setNombre(const string& nuevoNombre) {
    if (!nuevoNombre.empty()) {
        nombre = nuevoNombre;
    }
}

void Robot::setTipo(const string& nuevoTipo) {
    if (!nuevoTipo.empty()) {
        tipo = stringToCategoria(nuevoTipo);
    }
}

void Robot::setTipo(Categorias nuevoTipo) {
    tipo = nuevoTipo;
}
