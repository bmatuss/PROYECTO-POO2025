#ifndef BEBIDA_H
#define BEBIDA_H

#include "item.h"
#include <string>

class Bebida : public Item {
    private:
        bool alcohol=false; //Si es alcoholica o no
        

    public:
        Bebida(const std::string& nombre, int precio, bool alcohol)
            : Item(nombre, precio, false), alcohol(alcohol) {}

        virtual ~Bebida() {}

        std::string getTipo() const override {return "Bebida";}

};

#endif // BEBIDA_H