#ifndef BEBIDA_H
#define BEBIDA_H

#include "item.h"

class Bebida : public Item {

    public:
        Bebida(const std::string& nombre, int precio)
            : Item(nombre, precio) {}

        virtual ~Bebida() {}

        std::string getTipo() const override {return "Bebida";}

};

#endif // BEBIDA_H