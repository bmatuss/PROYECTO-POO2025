#include <iostream>
#include <string>
#include "UsuarioCaja.h"

void UsuarioCaja::procesarPago(Pedido *pedido) {
    double monto = pedido->getTotal();
    setTotalRecaudado(getTotalRecaudado() + monto);
    std::cout << "Total recaudado hasta ahora: " << getTotalRecaudado() << std::endl;
}
