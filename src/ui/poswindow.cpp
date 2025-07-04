#include "poswindow.h"
#include "ui_poswindow.h"
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include "../models/categoria.h"
#include "../models/item.h"
#include "../models/pedido.h"
#include "../models/mesa.h"
#include "cocinawindow.h"
#include "barrawindow.h"

PosWindow::PosWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PosWindow)
    , categoriaActual(nullptr)
    , pedidoActual(new Pedido(0))
    , ventanaCocina(nullptr)
    , ventanaBarra(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("pos");

    if (!Categoria::cargarDesdeJSON()) {
        Categoria::inicializarCategoriasDefecto();
        Categoria::agregarItemsEjemplo();
    }
    crearBotonesMesas();
    crearBotonesCategorias();
    ui->stackedWidget->setCurrentWidget(ui->login);

    
    listasPedidos.reserve(16);
    for (int i = 0; i < 16; ++i) {
        listasPedidos.push_back(new QListWidget(this));
    }
    
    
    mesas.reserve(16);
    for (int i = 1; i <= 16; ++i) {
        mesas.push_back(new Mesa(i));
    }
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
void PosWindow::mesaSeleccionada() {
    QPushButton* boton = qobject_cast<QPushButton*>(sender());
    if (boton) {
        int numeroMesa = boton->text().toInt();
        delete pedidoActual;
        pedidoActual = new Pedido(numeroMesa);
        // mostrar el QListWidget de la mesa seleccionada
        QVBoxLayout* layoutPedidos = this->findChild<QVBoxLayout*>("layoutPedidos");
        if (layoutPedidos && layoutPedidos->count() > 0) {
            QLayoutItem* item;
            while ((item = layoutPedidos->takeAt(0)) != nullptr) {
                if (item->widget()) item->widget()->setParent(nullptr);
                delete item;
            }
        }
        if (layoutPedidos)
            layoutPedidos->addWidget(listasPedidos[numeroMesa - 1]);
    }
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
            if (pedidoActual->getMesa() > 0) {
                int idx = pedidoActual->getMesa() - 1;
                listasPedidos[idx]->addItem(itemTexto);
                QVBoxLayout* layoutPedidos = this->findChild<QVBoxLayout*>("layoutPedidos");
                if (layoutPedidos) {
                    if (layoutPedidos->count() == 0 || layoutPedidos->itemAt(0)->widget() != listasPedidos[idx]) {
                        QLayoutItem* item;
                        while ((item = layoutPedidos->takeAt(0)) != nullptr) {
                            if (item->widget()) item->widget()->setParent(nullptr);
                            delete item;
                        }
                        layoutPedidos->addWidget(listasPedidos[idx]);
                    }
                }
            }
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
void PosWindow::on_enviarButton_clicked()
{
    if (pedidoActual && !pedidoActual->getItems().empty()) {
        if (ventanaCocina) {
            ventanaCocina->recibirPedido(pedidoActual);
        }
        if (ventanaBarra) {
            ventanaBarra->recibirPedido(pedidoActual);
        }
    
        int mesaActual = pedidoActual->getMesa();
        delete pedidoActual;
        pedidoActual = new Pedido(mesaActual);
        ui->stackedWidget->setCurrentWidget(ui->posPrincipal);
    }
}

void PosWindow::setCocinaWindow(cocinawindow* cocina)
{
    ventanaCocina = cocina;
}

void PosWindow::setBarraWindow(barrawindow* barra)
{
    ventanaBarra = barra;
}


void PosWindow::on_pagarButton_clicked() {
    if (pedidoActual && pedidoActual->getMesa() > 0) {
        int numeroMesa = pedidoActual->getMesa();
        double total = 0;
        

        QListWidget* listaMesa = listasPedidos[numeroMesa - 1];
        for (int i = 0; i < listaMesa->count(); ++i) {
            QString itemTexto = listaMesa->item(i)->text();
            
            int dollarIndex = itemTexto.lastIndexOf("$");
            if (dollarIndex != -1) {
                QString precioStr = itemTexto.mid(dollarIndex + 1);
                total += precioStr.toDouble();
            }
        }

        QDialog dialog(this);
        dialog.setWindowTitle("Pago de Mesa");
        QVBoxLayout* layout = new QVBoxLayout(&dialog);
        QLabel* label = new QLabel(QString("Total a pagar: $%1").arg(total), &dialog);
        layout->addWidget(label);
        QPushButton* cerrarButton = new QPushButton("Cerrar Mesa", &dialog);
        layout->addWidget(cerrarButton);
        connect(cerrarButton, &QPushButton::clicked, &dialog, &QDialog::accept);
        dialog.exec();

       
        Mesa* mesa = buscarMesaPorNumero(numeroMesa);
        if (mesa) {
            mesa->cerrarMesa();
        }
        
        
        listaMesa->clear();


        QVBoxLayout* layoutPedidos = this->findChild<QVBoxLayout*>("layoutPedidos");
        if (layoutPedidos) {
            QLayoutItem* item;
            while ((item = layoutPedidos->takeAt(0)) != nullptr) {
                if (item->widget()) {
                    item->widget()->setParent(nullptr);
                }
                delete item;
            }
        }

        delete pedidoActual;
        pedidoActual = nullptr;
        ui->stackedWidget->setCurrentWidget(ui->posPrincipal);
    }
}

Mesa* PosWindow::buscarMesaPorNumero(int numeroMesa) {
    for (Mesa* mesa : mesas) {
        if (mesa->getNumero() == numeroMesa) {
            return mesa;
        }
    }
    return nullptr;
}

