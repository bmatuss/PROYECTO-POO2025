#ifndef MENULOADER_H
#define MENULOADER_H

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class MenuLoader {
public:
    static bool cargarMenuDesdeJSON(const QString& rutaArchivo);
    static bool cargarMenuDesdeRecursos(); 
    
private:
    static void procesarCategoria(const QJsonObject& categoriaObj);
    static void procesarItem(const QJsonObject& itemObj, const QString& nombreCategoria);
};

#endif // MENULOADER_H