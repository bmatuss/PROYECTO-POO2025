#ifndef COMIDA_H
#define COMIDA_H


#include "item.h"


class Comida : public Item {

    public:
        Comida(const std::string& nombre, int precio)
            : Item(nombre, precio) {}

        virtual ~Comida() {}


        std::string getTipo() const override {return "Comida";}


};

#endif // COMIDA_H