/**
 * @file categoria.h
 * @brief Definición de la clase Categoria para organizar items del menú
 * @date 2025
 */

#ifndef CATEGORIA_H
#define CATEGORIA_H
#include <string>
#include <vector>
#include <QStringList>
#include "item.h"
#include "bebida.h"
#include "comida.h"

/**
 * @brief Clase que representa una categoría del menú del restaurante
 * 
 * Esta clase organiza los items del menú en categorías lógicas como
 * "Bebidas", "Comidas", "Postres", etc. Proporciona métodos estáticos
 * para gestionar todas las categorías del sistema y métodos de instancia
 * para gestionar los items de cada categoría individual.
 */
class Categoria{
    private:
        std::string nombre;                        ///< Nombre de la categoría
        std::vector<Item*> items;                  ///< Items que pertenecen a esta categoría
        static std::vector<Categoria*> categorias; ///< Vector estático con todas las categorías

    public:
        /**
         * @brief Constructor de la clase Categoria
         * @param nombre Nombre de la categoría a crear
         */
        Categoria(const std::string& nombre) : nombre(nombre) {}

        /**
         * @brief Obtiene el nombre de la categoría
         * @return std::string Nombre de la categoría
         */
        std::string getNombre() const {
            return nombre;
        }

        /**
         * @brief Agrega un item a esta categoría
         * @param item Puntero al item a agregar
         */
        void agregarItem(Item* item) {
            items.push_back(item);
        }

        /**
         * @brief Obtiene una lista con los nombres de todos los items de la categoría
         * @return QStringList Lista de nombres de items
         */
        QStringList getNombresItems() const {
            QStringList nombres;
            for (const Item* item : items) {
                nombres.append(QString::fromStdString(item->getNombre()));
            }
            return nombres;
        }

        /**
         * @brief Agrega una categoría al sistema (método estático)
         * @param categoria Puntero a la categoría a agregar
         */
        static void agregarCategoria(Categoria* categoria) {
            categorias.push_back(categoria);
        }

        /**
         * @brief Obtiene una lista con los nombres de todas las categorías
         * @return QStringList Lista de nombres de categorías
         */
        static QStringList getNombresCategorias() {
            QStringList nombres;
            for (const Categoria* categoria : categorias) {
                nombres.append(QString::fromStdString(categoria->getNombre()));
            }
            return nombres;
        }

        /**
         * @brief Busca una categoría por su nombre
         * @param nombre Nombre de la categoría a buscar
         * @return Categoria* Puntero a la categoría encontrada, nullptr si no existe
         */
        static Categoria* buscarCategoriaPorNombre(const std::string& nombre) {
            for (Categoria* categoria : categorias) {
                if (categoria->getNombre() == nombre) {
                    return categoria;
                }
            }
            return nullptr;
        }
        
        /**
         * @brief Busca un item por su nombre dentro de esta categoría
         * @param nombre Nombre del item a buscar
         * @return Item* Puntero al item encontrado, nullptr si no existe
         */
        Item* buscarItemPorNombre(const std::string& nombre) const {
            for (Item* item : items) {
                if (item->getNombre() == nombre) {
                    return item;
                }
            }
            return nullptr;
        }

        /**
         * @brief Limpia todas las categorías del sistema y libera memoria
         */
        static void limpiarCategorias() {
            for (Categoria* categoria : categorias) {
                delete categoria;
            }
            categorias.clear();
        }

        /**
         * @brief Inicializa las categorías por defecto del sistema
         * 
         * Crea las categorías básicas: Bebidas, Comidas, Postres y Extras.
         * Limpia las categorías existentes antes de crear las nuevas.
         */
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

        /**
         * @brief Agrega items de ejemplo a las categorías por defecto
         * 
         * Popula las categorías predefinidas con items de ejemplo
         * para demostrar el funcionamiento del sistema.
         */
        static void agregarItemsEjemplo() {
            Categoria* bebidas = buscarCategoriaPorNombre("Bebidas");
            Categoria* comidas = buscarCategoriaPorNombre("Comidas");
            Categoria* postres = buscarCategoriaPorNombre("Postres");
            Categoria* extras = buscarCategoriaPorNombre("Extras");
            
            if (bebidas) {
                bebidas->agregarItem(new Bebida("Coca Cola", 2500, false));
                bebidas->agregarItem(new Bebida("Agua", 1500, false));
                bebidas->agregarItem(new Bebida("Jugo Natural", 3000, false));
                bebidas->agregarItem(new Bebida("Cerveza", 4000, true));
            }
            
            if (comidas) {
                comidas->agregarItem(new Comida("Pizza Margherita", 12000, true));
                comidas->agregarItem(new Comida("Hamburguesa", 8500, false));
                comidas->agregarItem(new Comida("Ensalada César", 7000, false));
                comidas->agregarItem(new Comida("Pasta", 9000, true));
            }
            
            if (postres) {
                postres->agregarItem(new Comida("Helado", 3500, true));
                postres->agregarItem(new Comida("Torta de Chocolate", 4500, false));
                postres->agregarItem(new Comida("Flan", 3000, false));
            }
            
            if (extras) {
                extras->agregarItem(new Comida("Papas Fritas", 2500, true));
                extras->agregarItem(new Comida("Pan de Ajo", 2000, true));
                extras->agregarItem(new Comida("Salsa Extra", 500, true));
            }
        }
        
        /**
         * @brief Carga categorías e items desde un archivo JSON
         * @param rutaArchivo Ruta al archivo JSON (opcional, usa archivo por defecto si está vacío)
         * @return bool true si la carga fue exitosa, false en caso contrario
         */
        static bool cargarDesdeJSON(const QString& rutaArchivo = "");
};

#endif // CATEGORIA_H