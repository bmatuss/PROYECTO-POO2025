#include "poswindow.h"
#include "ui_poswindow.h"
#include <QPushButton>
#include "../models/categoria.h"
#include "../models/item.h"
#include "../models/pedido.h"

PosWindow::PosWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PosWindow)
    , categoriaActual(nullptr)
    , pedidoActual(new Pedido(0))
{
    ui->setupUi(this);
    setWindowTitle("pos");

    Categoria::inicializarCategoriasDefecto();
    Categoria::agregarItemsEjemplo();
    
    crearBotonesMesas();
    crearBotonesCategorias();

    ui->stackedWidget->setCurrentWidget(ui->login);
}

PosWindow::~PosWindow()
{
    delete ui;
}

void PosWindow::on_lineEdit_returnPressed()
{
    ui->stackedWidget->setCurrentWidget(ui->posPrincipal);
}

void PosWindow::crearBotonesMesas()
{
    for (int i=1;i <= 16; i++){
        QPushButton *boton = new QPushButton(QString::number(i), this);

        int fila = (i-1) / 4;
        int columna = (i-1)%4;

        connect(boton,&QPushButton::clicked,this,&PosWindow::mesaSeleccionada);

        ui->gridMesas->addWidget(boton, fila, columna);
    }
}
void PosWindow::crearBotonesCategorias(){
    QStringList categorias = Categoria::getNombresCategorias();
    
    for (int i = 0; i < categorias.size(); i++){
        QPushButton *boton = new QPushButton(categorias[i], this);
        
        int fila = i/2;
        int columna = i%2;
        connect(boton, &QPushButton::clicked, this, &PosWindow::categoriaSeleccionada);

        ui->gridCategoria->addWidget(boton, fila, columna);
    }
}
void PosWindow::crearBotonesItems(){
    QLayoutItem *child;
    while ((child = ui->gridItems->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    
    if (categoriaActual == nullptr) {
        return;
    }
    
    QStringList items = categoriaActual->getNombresItems();
    
    for (int i = 0; i < items.size(); i++){
        QPushButton *boton = new QPushButton(items[i], this);

        int fila = i/2;
        int columna = i%2;
        connect(boton, &QPushButton::clicked, this, &PosWindow::itemSeleccionado);

        ui->gridItems->addWidget(boton, fila, columna);
    }
}
void PosWindow::mesaSeleccionada(){
    ui->stackedWidget->setCurrentWidget(ui->menu);
}

void PosWindow::itemSeleccionado(){
    QPushButton* boton = qobject_cast<QPushButton*>(sender());
    if(boton && categoriaActual){
        QString nombreItem = boton->text();
        Item* item =buscarItemEnCategoria(nombreItem.toStdString());
        if (item) {
            pedidoActual->agregarItem(item, 1, "");

            QString itemTexto= QString("%1 - $%2").arg(item->getNombre().c_str()).arg(item->getPrecio());
            ui->listaPedido->addItem(itemTexto);
        }
    }
    ui->stackedCategorias->setCurrentWidget(ui->pageCategoria);
}
void PosWindow::categoriaSeleccionada(){
    QPushButton* boton = qobject_cast<QPushButton*>(sender());
    if (boton) {
        QString nombreCategoria = boton->text();
        categoriaActual = Categoria::buscarCategoriaPorNombre(nombreCategoria.toStdString());
        
        if (categoriaActual) {
            crearBotonesItems();
            ui->stackedCategorias->setCurrentWidget(ui->pageItems);
        }
    }
}

Item* PosWindow::buscarItemEnCategoria(const std::string& nombreItem) {
    if (categoriaActual) {
        return categoriaActual->buscarItemPorNombre(nombreItem);
    }
    return nullptr;
}
