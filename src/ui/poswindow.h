#ifndef POSWINDOW_H
#define POSWINDOW_H

#include <QMainWindow>
#include <string>
#include "../models/categoria.h"
#include "../models/pedido.h"
class cocinawindow;
class barrawindow;


    

namespace Ui {
class PosWindow;
}

class PosWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PosWindow(QWidget *parent = nullptr);
    ~PosWindow();
    
    void setCocinaWindow(cocinawindow* cocina);
    void setBarraWindow(barrawindow* barra);

private:
    Ui::PosWindow *ui;
    Categoria* categoriaActual;
    Pedido* pedidoActual;
    cocinawindow* ventanaCocina;
    barrawindow* ventanaBarra;
    Item* buscarItemEnCategoria(const std::string& nombreItem);

private slots:
    void on_lineEdit_returnPressed();
    void on_enviarButton_clicked();
    void crearBotonesMesas();
    void crearBotonesCategorias();
    void crearBotonesItems();
    void mesaSeleccionada();
    void itemSeleccionado();
    void categoriaSeleccionada();
};

#endif // POSWINDOW_H
