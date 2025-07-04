#ifndef MESA_H
#define MESA_H

#include <vector>
#include <QString>
#include "pedido.h"

enum EstadoMesa {
    ABIERTA,
    CERRADA
};

class Mesa {
private:
    int numero;
    EstadoMesa estado;
    std::vector<Pedido*> pedidos;

public:
    Mesa(int numero) : numero(numero), estado(ABIERTA) {}

    void agregarPedido(Pedido* pedido) {
        if (estado == ABIERTA) {
            pedidos.push_back(pedido);
        }
    }

    void cerrarMesa() {
        estado = CERRADA;
    }

    bool estaAbierta() const {
        return estado == ABIERTA;
    }

    const std::vector<Pedido*>& getPedidos() const {
        return pedidos;
    }

    int getNumero() const {
        return numero;
    }
};

#endif // MESA_H
