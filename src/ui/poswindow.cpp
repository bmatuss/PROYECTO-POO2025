#include "poswindow.h"
#include "ui_poswindow.h"
#include <QPushButton>

PosWindow::PosWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PosWindow)
{
    ui->setupUi(this);
    setWindowTitle("pos");

    crearBotonesMesas();
    crearBotonesCategorias();
    crearBotonesItems();
}

PosWindow::~PosWindow()
{
    delete ui;
}

void PosWindow::on_lineEdit_returnPressed()
{
    // habria q validad q el id exista etc 
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
     // habria q sacarlos del .json
    // por ahora los dejo hardcodeados
    QStringList categorias = {"Bebidas", "Comidas", "Postres", "Extras"};
    for (int i=0;i < categorias.size(); i++){
        QPushButton *boton = new QPushButton(categorias[i],this);
        
        int fila = i/2;
        int columna = i%2;
        connect(boton,&QPushButton::clicked,this,&PosWindow::categoriaSeleccionada);

        ui->gridCategoria->addWidget(boton, fila, columna);
    }
}
void PosWindow::crearBotonesItems(){
    // habria q sacarlos del .json
    // por ahora los dejo hardcodeados
    QStringList items = {"Coca Cola", "Pizza", "Helado", "Papas Fritas"};
    for (int i=0;i < items.size(); i++){
        QPushButton *boton = new QPushButton(items[i],this);

        int fila = i/2;
        int columna = i%2;
        connect(boton, &QPushButton::clicked, this, &PosWindow::itemSeleccionado);

        ui->gridItems->addWidget(boton, fila, columna);
    }
}
void PosWindow::mesaSeleccionada(){
    //selecciona la mesa y muestra el menu (parte de categorias)
    ui->stackedWidget->setCurrentWidget(ui->menu);
}

void PosWindow::itemSeleccionado(){
    //selecciona el item y devuelve a menu de categorias
    ui->stackedCategorias->setCurrentWidget(ui->pageCategoria);
}
void PosWindow::categoriaSeleccionada(){
    //selecciona la categoria y muestra los items
    ui->stackedCategorias->setCurrentWidget(ui->pageItems);
}
