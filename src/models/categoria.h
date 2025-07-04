#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>
#include <vector>
#include <QStringList>
#include "item.h"

class Categoria{
    private:
        std::string nombre;
        std::vector<Item*> items;
        static std::vector<Categoria*> categorias;

    public:
        Categoria(const std::string& nombre) : nombre(nombre) {}

        std::string getNombre() const {
            return nombre;
        }

        void agregarItem(Item* item) {
            items.push_back(item);
        }

        QStringList getNombresItems() const {
            QStringList nombres;
            for (const Item* item : items) {
                nombres.append(QString::fromStdString(item->getNombre()));
            }
            return nombres;
        }

        static void agregarCategoria(Categoria* categoria) {
            categorias.push_back(categoria);
        }

        static QStringList getNombresCategorias() {
            QStringList nombres;
            for (const Categoria* categoria : categorias) {
                nombres.append(QString::fromStdString(categoria->getNombre()));
            }
            return nombres;
        }

        static Categoria* buscarCategoriaPorNombre(const std::string& nombre) {
            for (Categoria* categoria : categorias) {
                if (categoria->getNombre() == nombre) {
                    return categoria;
                }
            }
            return nullptr;
        }
        Item* buscarItemPorNombre(const std::string& nombre) const {
    for (Item* item : items) {
        if (item->getNombre() == nombre) {
            return item;
        }
    }
    return nullptr;
}

        static void limpiarCategorias() {
            for (Categoria* categoria : categorias) {
                delete categoria;
            }
            categorias.clear();
        }

        static void inicializarCategoriasDefecto() {
            limpiarCategorias();
            
            Categoria* bebidas = new Categoria("Bebidas");
            Categoria* comidas = new Categoria("Comidas");
            Categoria* postres = new Categoria("Postres");
            Categoria* extras = new Categoria("Extras");
            
            agregarCategoria(bebidas);
            agregarCategoria(comidas);
            agregarCategoria(postres);
            agregarCategoria(extras);
        }

        static void agregarItemsEjemplo() {
            Categoria* bebidas = buscarCategoriaPorNombre("Bebidas");
            Categoria* comidas = buscarCategoriaPorNombre("Comidas");
            Categoria* postres = buscarCategoriaPorNombre("Postres");
            Categoria* extras = buscarCategoriaPorNombre("Extras");
            
            if (bebidas) {
                bebidas->agregarItem(new Item("Coca Cola", 2500, false));
                bebidas->agregarItem(new Item("Agua", 1500, true));
                bebidas->agregarItem(new Item("Jugo Natural", 3000, true));
                bebidas->agregarItem(new Item("Cerveza", 4000, false));
            }
            
            if (comidas) {
                comidas->agregarItem(new Item("Pizza Margherita", 12000, true));
                comidas->agregarItem(new Item("Hamburguesa", 8500, false));
                comidas->agregarItem(new Item("Ensalada César", 7000, false));
                comidas->agregarItem(new Item("Pasta", 9000, true));
            }
            
            if (postres) {
                postres->agregarItem(new Item("Helado", 3500, true));
                postres->agregarItem(new Item("Torta de Chocolate", 4500, false));
                postres->agregarItem(new Item("Flan", 3000, false));
            }
            
            if (extras) {
                extras->agregarItem(new Item("Papas Fritas", 2500, true));
                extras->agregarItem(new Item("Pan de Ajo", 2000, true));
                extras->agregarItem(new Item("Salsa Extra", 500, true));
            }
        }
};

#endif // CATEGORIA_H