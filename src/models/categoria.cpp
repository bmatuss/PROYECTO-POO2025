#include "categoria.h"
#include "menuloader.h"
std::vector<Categoria*> Categoria::categorias;
bool Categoria::cargarDesdeJSON(const QString& rutaArchivo) {
    if (rutaArchivo.isEmpty()) {
        return MenuLoader::cargarMenuDesdeRecursos();
    } else {
        return MenuLoader::cargarMenuDesdeJSON(rutaArchivo);
    }
}