#pragma once
#include <string>

// Enum para las categorías de robots
enum class Categorias {
    SUMO,
    SEGUIDOR_DE_LINEA,
    COMBATE
};

// Función auxiliar para convertir enum a string (para presentación)
inline std::string categoriaToString(Categorias categoria) {
    switch (categoria) {
        case Categorias::SUMO:
            return "Sumo";
        case Categorias::SEGUIDOR_DE_LINEA:
            return "Seguidor de linea";
        case Categorias::COMBATE:
            return "Combate";
        default:
            return "Desconocida";
    }
}

// Función auxiliar para convertir string a enum
inline Categorias stringToCategoria(const std::string& tipo) {
    if (tipo == "Sumo" || tipo == "SUMO") {
        return Categorias::SUMO;
    } else if (tipo == "Seguidor de linea" || tipo == "SEGUIDOR_DE_LINEA") {
        return Categorias::SEGUIDOR_DE_LINEA;
    } else if (tipo == "Combate" || tipo == "COMBATE") {
        return Categorias::COMBATE;
    }
    // Por defecto retorna SUMO si no se reconoce
    return Categorias::SUMO;
}

// Clase Robot: representa un robot participante en la competencia.
// Atributos privados + acceso controlado (encapsulamiento).
class Robot {
private:
    std::string nombre;
    Categorias tipo; // Usa enum en lugar de string

public:
    // Constructor con lista de inicializacion
    Robot(const std::string& nombre, const std::string& tipo);
    Robot(const std::string& nombre, Categorias tipo);

    // Getters
    std::string getNombre() const;
    std::string getTipo() const;      // Retorna string para compatibilidad con presentación
    Categorias getTipoEnum() const;   // Retorna el enum para comparaciones internas

    // Setters (con validacion basica)
    void setNombre(const std::string& nuevoNombre);
    void setTipo(const std::string& nuevoTipo);
    void setTipo(Categorias nuevoTipo);
};
