/**
 * @file item.h
 * @brief Clase base para items del menú
 * @date 2025
 */

#ifndef ITEM_H
#define ITEM_H
#include <string>

/**
 * @brief Clase base para elementos del menú
 * 
 * Base para comidas y bebidas del restaurante.
 */
class Item{
    private:
        std::string nombre;  ///< Nombre del item
        int precio;          ///< Precio del item en la moneda local
        bool vegano;         ///< Indica si el item es vegano

    public:
        /**
         * @brief Constructor del item
         * @param nombre Nombre del item
         * @param precio Precio
         * @param vegano Si es vegano o no
         */
        Item(const std::string& nombre, const int precio, const bool vegano)
            : nombre(nombre), precio(precio), vegano(vegano) {}

        /**
         * @brief Destructor virtual
         */
        virtual ~Item();

        /**
         * @brief Obtiene el nombre del item
         * @return std::string Nombre del item
         */
        std::string getNombre() const{return nombre;}
        
        /**
         * @brief Obtiene el precio del item
         * @return int Precio del item
         */
        int getPrecio() const{return precio;}

        /**
         * @brief Método virtual puro para obtener el tipo de item
         * @return std::string Tipo del item (debe ser implementado por las clases derivadas)
         */
        virtual std::string getTipo() const = 0;



};

#endif // ITEM_H