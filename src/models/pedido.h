#ifndef PEDIDO_H
#define PEDIDO_H

#include <vector>
#include "item.h"
#include "pedidoItem.h"
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
        int getMontoTotal() const;
};

#endif // PEDIDO_H