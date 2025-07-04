/**
 * @file comida.h
 * @brief Definición de la clase Comida para platos del menú
 * @date 2025
 */

#ifndef COMIDA_H
#define COMIDA_H

#include "item.h"

/**
 * @brief Clase que representa un plato de comida en el menú del restaurante
 * 
 * Esta clase hereda de Item y representa platos de comida que pueden ser
 * veganos o no veganos. Incluye toda la comida sólida del menú.
 */
class Comida : public Item {

    public:
        /**
         * @brief Constructor de la clase Comida
         * @param nombre Nombre del plato de comida
         * @param precio Precio del plato en la moneda local
         * @param vegano Indica si el plato es vegano
         */
        Comida(const std::string& nombre, int precio, bool vegano)
            : Item(nombre, precio, vegano) {}

        /**
         * @brief Destructor virtual de la clase Comida
         */
        virtual ~Comida() {}

        /**
         * @brief Obtiene el tipo de item
         * @return std::string Siempre retorna "Comida"
         */
        std::string getTipo() const override {return "Comida";}

};

#endif // COMIDA_H