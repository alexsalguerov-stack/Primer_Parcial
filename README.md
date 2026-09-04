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


-El tamaño de robot string era de 64 bytes y el de enum es de 32 bytes pues actua en c++ como entero. 
-La ejecución es mas rapida.
