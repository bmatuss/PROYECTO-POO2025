#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include <string>
#include <vector>
#include <QString>
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
        double getMontoTotal() const;
        // devuelve el numero de mesa
        int getMesa() const { return mesa; }
        const std::vector<PedidoItem*>& getItems() const { return items; }



        
        
        




};

#endif // PEDIDO_H
