/**
 * @file pedidoItem.h
 * @brief Definición de la clase PedidoItem para items individuales dentro de un pedido
 * @date 2025
 */

#ifndef PEDIDOITEM_H
#define PEDIDOITEM_H

#include <string>
#include "item.h"

/**
 * @brief Clase que representa un item individual dentro de un pedido
 * 
 * Esta clase encapsula un item del menú junto con la cantidad solicitada
 * y comentarios especiales (ej: "sin mayo", "extra picante", etc.).
 * Permite personalizar cada item dentro de un pedido.
 */
class PedidoItem {
    private:
        Item* item;              ///< Puntero al item del menú
        int cantidad;            ///< Cantidad de este item en el pedido
        std::string comentario;  ///< Comentarios especiales (ej: "sin mayo")

    public:
        /**
         * @brief Constructor de la clase PedidoItem
         * @param item Puntero al item del menú a incluir en el pedido
         * @param cantidad Cantidad del item solicitada
         * @param comentario Comentarios o instrucciones especiales para la preparación
         */
        PedidoItem(Item* item, int cantidad, const std::string& comentario)
            : item(item), cantidad(cantidad), comentario(comentario) {}

        /**
         * @brief Destructor de la clase PedidoItem
         */
        ~PedidoItem();

        /**
         * @brief Obtiene el item del menú asociado
         * @return Item* Puntero al item del menú
         */
        Item* getItem() const {return item; }
        
        /**
         * @brief Obtiene la cantidad solicitada del item
         * @return int Cantidad del item en el pedido
         */
        int getCantidad() const {return cantidad; }
        
        /**
         * @brief Obtiene los comentarios especiales del item
         * @return std::string Comentarios o instrucciones especiales
         */
        std::string getComentario() const {return comentario;}
        
        /**
         * @brief Calcula el subtotal de este item en el pedido
         * @return double Precio total (precio unitario × cantidad)
         */
        double getSubtotal() const { return item->getPrecio() * cantidad; }
};

#endif // PEDIDOITEM_H