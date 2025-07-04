#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario {
    private:
        int const id;
        std::string  const nombre;
    public:
        Usuario(int id, const std::string nombre)
            : id(id), nombre(nombre) {}
        int getId() const { return id; }
        std::string getNombre() const { return nombre; }

};

#endif // USUARIO_H