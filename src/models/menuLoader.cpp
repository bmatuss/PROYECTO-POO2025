#include "menuLoader.h"
#include "categoria.h"
#include "bebida.h"
#include "comida.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

bool MenuLoader::cargarMenuDesdeRecursos() {
    return cargarMenuDesdeJSON(":/data/menu.json");
}

bool MenuLoader::cargarMenuDesdeJSON(const QString& rutaArchivo) {
    QFile archivo(rutaArchivo);
    
    if (!archivo.open(QIODevice::ReadOnly)) {
        qDebug() << "No se pudo abrir el archivo:" << rutaArchivo;
        return false;
    }
    
    QByteArray datos = archivo.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(datos);
    
    if (doc.isNull()) {
        qDebug() << "JSON inválido";
        return false;
    }
    
    QJsonObject raiz = doc.object();
    QJsonArray categorias = raiz["categorias"].toArray();
    
    // Limpiar categorías existentes
    Categoria::limpiarCategorias();
    
    // Procesar cada categoría
    for (const auto& categoria : categorias) {
        procesarCategoria(categoria.toObject());
    }
    
    return true;
}

void MenuLoader::procesarCategoria(const QJsonObject& categoriaObj) {
    QString nombre = categoriaObj["nombre"].toString();
    Categoria* categoria = new Categoria(nombre.toStdString());
    Categoria::agregarCategoria(categoria);
    
    QJsonArray items = categoriaObj["items"].toArray();
    for (const auto& item : items) {
        procesarItem(item.toObject(), nombre);
    }
}

void MenuLoader::procesarItem(const QJsonObject& itemObj, const QString& nombreCategoria) {
    QString nombre = itemObj["nombre"].toString();
    int precio = itemObj["precio"].toInt();
    QString tipo = itemObj["tipo"].toString();
    bool vegano = itemObj["vegano"].toBool();
    
    Item* item = nullptr;
    
    if (tipo == "bebida") {
        bool alcohol = itemObj["alcohol"].toBool();
        item = new Bebida(nombre.toStdString(), precio, alcohol);
    } else if (tipo == "comida") {
        item = new Comida(nombre.toStdString(), precio, vegano);
    }
    
    if (item) {
        Categoria* categoria = Categoria::buscarCategoriaPorNombre(nombreCategoria.toStdString());
        if (categoria) {
            categoria->agregarItem(item);
        }
    }
}