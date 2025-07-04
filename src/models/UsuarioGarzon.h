#ifndef USUARIOGARZON_H
#define USUARIOGARZON_H
#include "Usuario.h"
#include <iostream>
#include <string>

class UsuarioGarzon : public Usuario {
    int total_comandas; // Total de comandas enviadas por el garzón en el día
    
public:
    UsuarioGarzon(int id, const std::string& nombre)
        : Usuario(id, nombre), total_comandas(0) {};
    void enviar_comanda();
    int getTotalComandas() const {
        return total_comandas;
    }
};

#endif // USUARIOGARZON_H