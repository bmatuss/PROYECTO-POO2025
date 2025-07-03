#ifndef ITEM_H
#define ITEM_H
#include <string>


class Item{
    private:
        std::string nombre;
        int precio;

        //----que mas puede ser??



    public:
        Item(const std::string& nombre, int precio)
            : nombre(nombre), precio(precio) {}

        virtual ~Item() {}

        //getters
        std::string getNombre() const{return nombre;}
        int getPrecio() const{return precio;}
        virtual std::string getTipo() const = 0;



};

#endif // ITEM_H