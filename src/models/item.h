#ifndef ITEM_H
#define ITEM_H
#include <string>


class Item{
    private:
        std::string nombre;
        int precio;
        bool vegano;   //neaaaaaaaaaaaaa sacalo sino pinta KJKJASJAKSJAKS 

        //----que mas puede ser??



    public:
        Item(const std::string& nombre, const int precio, const bool vegano)
            : nombre(nombre), precio(precio), vegano(vegano) {}

        virtual ~Item() {}

        //getters
        std::string getNombre() const{return nombre;}
        int getPrecio() const{return precio;}
        virtual std::string getTipo();



};

#endif // ITEM_H