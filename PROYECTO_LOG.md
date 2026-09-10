# Log de Desarrollo: Sistema de Gestión de Competencia de Robótica

## 📅 Estado del Proyecto
- **Fecha de última actualización:** 2026-09-10
- **Objetivo:** Implementación del Primer Parcial de POO (Programación Orientada a Objetos).
- **Restricción Principal:** Uso de POO sin herencia.

## 🏗️ Arquitectura del Sistema

### 1. Capas de Diseño
- **Capa de Presentación (Vista):** `mainframe.cpp`. Responsable exclusivamente de la interacción con el usuario y la representación visual de los datos mediante tablas formateadas con `<iomanip>`.
- **Capa de Lógica (Modelo):** Clases `Organizador` y `Referee`. Gestionan las reglas de negocio, el flujo de la competencia y la resolución de batallas.

### 2. Definición de Clases y Responsabilidades
| Clase | Responsabilidad | Atributos Clave |
| :--- | :--- | :--- |
| **Robot** | Representar un robot participante. | `nombre`, `tipo` |
| **Integrante** | Representar un estudiante del equipo. | `nombre`, `carrera` |
| **Equipo** | Agrupar integrantes y robots. | `nombreEquipo`, `vector<Integrante>`, `vector<Robot>` |
| **Organizador** | Gestionar el registro, agrupar robots por disciplina y coordinar la competencia. | `vector<Equipo>` |
| **Referee** | Resolver enfrentamientos de forma aleatoria. | N/A (Lógica de decisión) |

## 📂 Estructura de Archivos
- **Raíz:** `T:\Clases\GitHub\Primer_Parcial\mainframe.cpp`
- **Cabeceras (.h):** `T:\Clases\GitHub\Primer_Parcial\Clases\`
- **Implementaciones (.cpp):** `T:\Clases\GitHub\Primer_Parcial\Estructura\`

## ✅ Avances Realizados
1.  **Sincronización de Nombres:** Se corrigieron errores de inclusión (ej. `Integrante.h` vs `Integrantes.h`).
2.  **Implementación de POO:** Se transformaron las funciones sueltas en clases formales (`Organizador` y `Referee`).
3.  **Flujo de Registro:** Se trasladó la lógica de captura de datos del `mainframe` al `Organizador` para respetar el encapsulamiento.
4.  **Interfaz de Tablas:** Se implementaron funciones de dibujo en el `mainframe` utilizando `std::setw` y `std::left` para mostrar:
    - Tabla de equipos inscritos.
    - Tabla de emparejamientos por disciplina.
    - Tabla de ganadores finales.
5.  **Lógica de Batallas:** El `Referee` implementa la selección aleatoria de ganadores mediante el uso de `<random>`.

## 🚩 Notas para Sesiones Futuras
- Al reiniciar el proyecto, leer este archivo y el `mainframe.cpp`.
- Asegurarse de que cualquier cambio en la lógica de negocio se realice en los archivos `.cpp` dentro de la carpeta `Estructura/`.
- El `mainframe.cpp` solo debe llamar a los métodos públicos del `Organizador` y `Referee`.
