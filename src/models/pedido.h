#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <string>
#include <vector>
#include <QString>
#include "item.h"
#include "pedidoitem.h"
// el pedido formado por una array de PedidoItem(item,cantidad,comentario)
// cada Pedido tiene una mesa asociada
class Pedido {
    private:
        std::vector<PedidoItem*> items;
        int mesa;
    

    public:
        Pedido(int mesa) : mesa(mesa) {}
        ~Pedido() {
            for (PedidoItem* item : items) {
                delete item;
            }
        }

        void agregarItem(Item* item, int cantidad, const std::string& comentario);
        //monto cuenta 
        double getMontoTotal() const;
        // devuelve el numero de mesa
        int getMesa() const { return mesa; }



        
        /*int getCantidad(Item* item) const {
            for (const PedidoItem* pedidoItem : items) {
                if (pedidoItem->getItem() == item) {
                    return pedidoItem->getCantidad();
                }
            }
            return 0; // Si el item no está en el pedido, devuelve 0
        }
        QString getComentario(Item* item) {
            for (const PedidoItem* pedidoItem : items) {
                if (pedidoItem->getItem() == item) {
                    return QString::fromStdString(pedidoItem->getComentario());
                }
            }
            return QString(); 
        }*/




};

#endif // PEDIDO_H