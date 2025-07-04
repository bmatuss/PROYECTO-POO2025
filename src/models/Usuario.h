/**
 * @file Usuario.h
 * @brief Definición de la clase base Usuario para empleados del restaurante
 * @date 2025
 */

#ifndef USUARIO_H
#define USUARIO_H
#include <string>

/**
 * @brief Clase base abstracta para representar usuarios del sistema
 * 
 * Esta clase sirve como base para todos los tipos de empleados
 * del restaurante (garzones, cajeros, etc.). Contiene la información
 * básica común a todos los usuarios del sistema.
 */
class Usuario {
    private:
        int const id;              ///< Identificador único del usuario (inmutable)
        std::string const nombre;  ///< Nombre del usuario (inmutable)
        
    public:
        /**
         * @brief Constructor de la clase Usuario
         * @param id Identificador único del usuario
         * @param nombre Nombre completo del usuario
         */
        Usuario(int id, const std::string nombre)
            : id(id), nombre(nombre) {}
            
        /**
         * @brief Destructor virtual para permitir herencia polimórfica
         */
        virtual ~Usuario() = default;
        
        /**
         * @brief Obtiene el ID del usuario
         * @return int Identificador único del usuario
         */
        int getId() const { return id; }
        
        /**
         * @brief Obtiene el nombre del usuario
         * @return std::string Nombre completo del usuario
         */
        std::string getNombre() const { return nombre; }

};

#endif // USUARIO_H