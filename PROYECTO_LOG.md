# Log de Desarrollo: Sistema de Gestión de Competencia de Robótica

## 📅 Estado del Proyecto
- **Fecha de última actualización:** 2026-09-15
- **Objetivo:** Implementación del Primer Parcial de POO (Programación Orientada a Objetos).
- **Restricción Principal:** Uso de POO sin herencia.

## 🏗️ Arquitectura del Sistema

### 1. Capas de Diseño
- **Capa de Presentación (Vista):** `mainframe.cpp`. Responsable exclusivamente de la interacción con el usuario y la representación visual de los datos mediante tablas formateadas con `<iomanip>`.
- **Capa de Lógica (Modelo):** Clases `Organizador` y `Referee`. Gestionan las reglas de negocio, el flujo de la competencia y la resolución de batallas.

### 2. Definición de Clases y Responsabilidades
| Clase | Responsabilidad | Atributos Clave |
| :--- | :--- | :--- |
| **Robot** | Representar un robot participante. | `nombre`, `tipo (enum Categorias)` |
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
6.  **Refactor con Enum Categorias (2026-09-15):** Se cambió el tipo de dato `Robot::tipo` de `std::string` a `enum class Categorias` para mejorar:
    - **Rendimiento:** El enum actúa como entero (32 bytes) vs string (64 bytes).
    - **Velocidad de ejecución:** Las comparaciones de enteros son más rápidas que las de strings.
    - **Seguridad de tipos:** Solo se permiten valores válidos (SUMO, SEGUIDOR_DE_LINEA, COMBATE).
    - **Funciones auxiliares:** Se implementaron `categoriaToString()` y `stringToCategoria()` para conversiones transparentes.

### 6.1 Detalles del Refactor con Enum
- **Archivo modificado:** `Clases/Robot.h`
  - Enum definido: `enum class Categorias { SUMO, SEGUIDOR_DE_LINEA, COMBATE }`
  - Constructor actualizado: `Robot(const std::string& nombre, const std::string& tipo)` (para compatibilidad)
  - Nuevo constructor: `Robot(const std::string& nombre, Categorias tipo)` (uso directo de enum)
  - Getters actualizados:
    - `getNombre()` → retorna `std::string`
    - `getTipo()` → retorna `std::string` (conversión desde enum)
    - `getTipoEnum()` → retorna `Categorias` (para comparaciones internas)

- **Archivo actualizado:** `Estructura/Robot.cpp`
  - Implementación de ambos constructores con manejo de conversión string-enum.
  - El método `getTipo()` utiliza `categoriaToString()` para retornar una cadena legible.

- **Archivo actualizado:** `Estructura/Organizador.cpp`
  - Métodos actualizados para utilizar `getTipoEnum()` en lugar de `getTipo()` para comparaciones internas.
  - Mantiene compatibilidad con la presentación usando `categoriaToString()`.

## 🚩 Notas para Sesiones Futuras
- Al reiniciar el proyecto, leer este archivo y el `mainframe.cpp`.
- Asegurarse de que cualquier cambio en la lógica de negocio se realice en los archivos `.cpp` dentro de la carpeta `Estructura/`.
- El `mainframe.cpp` solo debe llamar a los métodos públicos del `Organizador` y `Referee`.
- **Importante:** Al trabajar con robots, usar `getTipoEnum()` internamente para comparaciones y `getTipo()` solo para presentación.
