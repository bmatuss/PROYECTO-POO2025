/**
 * @file bebida.h
 * @brief Definición de la clase Bebida para elementos líquidos del menú
 * @date 2025
 */

#ifndef BEBIDA_H
#define BEBIDA_H

#include "item.h"
#include <string>

/**
 * @brief Clase que representa una bebida en el menú del restaurante
 * 
 * Esta clase hereda de Item y representa bebidas que pueden ser alcohólicas 
 * o no alcohólicas. Las bebidas son consideradas automáticamente como no veganas.
 */
class Bebida : public Item {
    private:
        bool alcohol = false;  ///< Indica si la bebida contiene alcohol
        

    public:
        /**
         * @brief Constructor de la clase Bebida
         * @param nombre Nombre de la bebida
         * @param precio Precio de la bebida en la moneda local
         * @param alcohol Indica si la bebida contiene alcohol
         */
        Bebida(const std::string& nombre, int precio, bool alcohol)
            : Item(nombre, precio, false), alcohol(alcohol) {}

        /**
         * @brief Destructor virtual de la clase Bebida
         */
        virtual ~Bebida() {}

        /**
         * @brief Obtiene el tipo de item
         * @return std::string Siempre retorna "Bebida"
         */
        std::string getTipo() const override {return "Bebida";}

        /**
         * @brief Verifica si la bebida contiene alcohol
         * @return bool true si contiene alcohol, false en caso contrario
         */
        bool tieneAlcohol() const { return alcohol; }

};

#endif // BEBIDA_H