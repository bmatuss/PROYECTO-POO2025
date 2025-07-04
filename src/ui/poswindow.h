#ifndef POSWINDOW_H
#define POSWINDOW_H

#include <QMainWindow>
#include <string>
#include "../models/categoria.h"
#include "../models/pedido.h"


    

namespace Ui {
class PosWindow;
}

class PosWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PosWindow(QWidget *parent = nullptr);
    ~PosWindow();

private:
    Ui::PosWindow *ui;
    Categoria* categoriaActual;
    Pedido* pedidoActual; 
    Item* buscarItemEnCategoria(const std::string& nombreItem);

private slots:
    void on_lineEdit_returnPressed();
    void crearBotonesMesas();
    void crearBotonesCategorias();
    void crearBotonesItems();
    void mesaSeleccionada();
    void itemSeleccionado();
    void categoriaSeleccionada();
};

#endif // POSWINDOW_H
