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

        void agregarItem(Item* item, int cantidad, const std::string& comentario) {
            items.push_back(new PedidoItem(item, cantidad, comentario));
        }
        //monto cuenta 
        int getMontoTotal() const {
            int total = 0;
            for(PedidoItem* item : items){
                total += item->getItem()->getPrecio() * item->getCantidad();
            }
            return total; 
        }
};

#endif // PEDIDO_H