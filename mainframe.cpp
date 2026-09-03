#include <iostream>
#include <string>
#include <Equipo.h>
#include <Robot.h>
#include <Organizador.h>
#include <Referee.h>
#include <Integrantes.h>

Equipo registro(){
    std::string nombre_equipo;
    std::cout << "Ingresar nombre del equipo: ";
    std::getline(std::cin, nombre_equipo);
    
    Equipo equipo(nombre_equipo);

    int no_robot = 0;
    std::cout << "¿Cuantos robots tiene el equipo? ";
    std::cin no_robot;
    syd::cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i < no_robot; ++i) {
        std::string nombre_robot, clase_robot;
        std::cout << "  Robot " << (i + 1) << " - nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "  Robot " << (i + 1) << " - tipo (Sumo/Seguidor de linea/Combate/...): ";
        std::getline(std::cin, tipo);
        equipo.agregarRobot(Robot(nombre, tipo));
    }
}