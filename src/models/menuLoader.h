/**
 * @file menuLoader.h
 * @brief Definición de la clase MenuLoader para cargar menús desde archivos JSON
 * @date 2025
 */

#ifndef MENULOADER_H
#define MENULOADER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

/**
 * @brief Clase utilitaria para cargar menús desde archivos JSON
 * 
 * Esta clase proporciona métodos estáticos para cargar y procesar
 * menús del restaurante desde archivos JSON, tanto desde archivos
 * externos como desde recursos embebidos en la aplicación.
 */
class MenuLoader {
public:
    /**
     * @brief Carga un menú desde un archivo JSON externo
     * @param rutaArchivo Ruta completa al archivo JSON que contiene el menú
     * @return bool true si la carga fue exitosa, false en caso contrario
     */
    static bool cargarMenuDesdeJSON(const QString& rutaArchivo);
    
    /**
     * @brief Carga un menú desde los recursos embebidos de la aplicación
     * @return bool true si la carga fue exitosa, false en caso contrario
     */
    static bool cargarMenuDesdeRecursos(); 
    
private:
    /**
     * @brief Procesa una categoría individual del JSON
     * @param categoriaObj Objeto JSON que representa una categoría del menú
     */
    static void procesarCategoria(const QJsonObject& categoriaObj);
    
    /**
     * @brief Procesa un item individual del JSON
     * @param itemObj Objeto JSON que representa un item del menú
     * @param nombreCategoria Nombre de la categoría a la que pertenece el item
     */
    static void procesarItem(const QJsonObject& itemObj, const QString& nombreCategoria);
};

#endif // MENULOADER_H