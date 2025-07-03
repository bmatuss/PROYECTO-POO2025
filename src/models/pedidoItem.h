#ifndef PEDIDOITEM_H
#define PEDIDOITEM_H

#include "item.h"
// esta representa un item de un pedido 
//tiene comentarios y cantidades.
class PedidoItem {
    private:
        Item* item; 
        int cantidad;
        std::string comentario; // comentario ej: sin mayo

    public:
        PedidoItem(Item* item, int cantidad, const std::string& comentario)
            : item(item), cantidad(cantidad), comentario(comentario) {}

        ~PedidoItem();

        Item* getItem() const {return item; }
        int getCantidad() const {return cantidad; }
        std::string getComentario() const {return comentario;}
};

#endif // PEDIDOITEM_H