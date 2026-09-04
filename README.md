Diagramas 







¿Como incluir las categorias?

#pragma once
#include <string>

using namespace std;


robot.h 
enum Categorias {
SUMO,
COMBATE,
SEGUIDOR DE LINEA 
}

(COMO ATRIBUTO)
class robot {
private : 
string Nombre; //nombre
Categorias Tipos; //categoria 

public:
   
    Robot(const string& nombre, Categorias Tipos);
    string getNombre() const;
    string getTipo() const;


(VENTAJAS DEL CAMBIO STRING A ENUM: 
