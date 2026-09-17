

¿Como incluir las categorias?

Dentro del sistema de gestión de la competencia, la clase Robot es una de las entidades centrales. Cada robot participa en una única disciplina o categoría: Sumo, Seguidor de línea o Combate. Esta categoría determina las reglas que aplicará el Referee, los emparejamientos que generará el Organizador y la forma en que se presenta la información al usuario.

Originalmente, dicha categoría se almacenaba como un std::string dentro del atributo tipo. Durante la revisión del diseño se identificó que esta decisión introducía riesgos de integridad, ineficiencias y acoplamiento innecesario entre la lógica interna y la presentación. Como resultado, se propuso y ejecutó el cambio hacia un enum.



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
-Separación entre lógico y presentación (El método getTipoEnum() se usa para tomar decisiones y el método getTipo() para mostrar información)
