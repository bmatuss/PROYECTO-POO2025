#ifndef USUARIOCAJA_H
#define USUARIOCAJA_H
#include <iostream>
#include <string>
#include "Usuario.h"

class UsuarioCaja : public Usuario {
private:
    double total_recaudado = 0.0;
public:
    UsuarioCaja(int id, const std::string& nombre)
        : Usuario(id, nombre), total_recaudado(0.0) {}
    void procesarPago();
    void setTotalRecaudado(double total) {
        total_recaudado = total;
    }
    double getTotalRecaudado() const {
        return total_recaudado;
    }
};

#endif // USUARIOCAJA_H