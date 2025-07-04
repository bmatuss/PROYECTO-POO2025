/**
 * @file pedido.h
 * @brief Definición de la clase Pedido para gestionar órdenes del restaurante
 * @date 2025
 */

#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <string>
#include <vector>
#include <QString>
#include "item.h"
#include "pedidoItem.h"

/**
 * @brief Clase que representa un pedido de una mesa
 * 
 * El pedido está formado por un array de PedidoItem (item, cantidad, comentario).
 * Cada Pedido tiene una mesa asociada.
 */
class Pedido {
    private:
        std::vector<PedidoItem*> items;  ///< Vector de items en el pedido
        int mesa;                        ///< Número de la mesa que realizó el pedido
    

    public:
        /**
         * @brief Constructor de la clase Pedido
         * @param mesa Número de la mesa que realiza el pedido
         */
        Pedido(int mesa) : mesa(mesa) {}
        
        /**
         * @brief Destructor que libera la memoria de los items
         */
        ~Pedido() {
            for (PedidoItem* item : items) {
                delete item;
            }
        }

        /**
         * @brief Agrega un item al pedido
         * @param item Puntero al item a agregar
         * @param cantidad Cantidad del item
         * @param comentario Comentarios especiales para el item
         */
        void agregarItem(Item* item, int cantidad, const std::string& comentario);
        
        /**
         * @brief Calcula el monto total del pedido
         * @return double Monto total de la cuenta
         */
        double getMontoTotal() const;
        
        /**
         * @brief Obtiene el número de mesa del pedido
         * @return int Número de la mesa
         */
        int getMesa() const { return mesa; }
        
        /**
         * @brief Obtiene la lista de items del pedido
         * @return const std::vector<PedidoItem*>& Referencia constante al vector de items
         */
        const std::vector<PedidoItem*>& getItems() const { return items; }



        
        
        




};

#endif // PEDIDO_H
