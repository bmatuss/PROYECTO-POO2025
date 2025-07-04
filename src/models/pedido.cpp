#include "pedido.h"
#include "pedidoitem.h"
#include <iostream>
#include <string>

void Pedido::agregarItem(Item* item, int cantidad, const std::string& comentario) {
    items.push_back(new PedidoItem(item, cantidad, comentario));
}
double Pedido::getMontoTotal() const {
            int total = 0;
            for(PedidoItem* item : items){
                total += item->getItem()->getPrecio() *item->getCantidad();
            }
            return total; 
}

