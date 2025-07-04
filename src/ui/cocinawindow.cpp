#include "cocinawindow.h"
#include "ui_cocinawindow.h"
#include <string>
#include "../models/comida.h"

cocinawindow::cocinawindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cocinawindow)
{
    ui->setupUi(this);
    setWindowTitle("cocina");
    /*Pedido *pedido1 = new Pedido(1); //ese 1 es el numero de mesa
    pedido1->agregarItem(new Comida("Vino", 700, false), 1, "Merlot");
    pedido1->agregarItem(new Comida("Whisky", 1000, false), 1, "On the rocks");
    pedido1->agregarItem(new Comida("Agua con gas", 300, true), 1, "Con hielo");
    pedido1->agregarItem(new Comida("Piscola", 800, false), 3, "70 30");
    agregarMesa(pedido1->getMesa(), ui->Comanda1);
    for (size_t i = 0; i < pedido1->getItems().size(); i++)
    {
        PedidoItem* item= pedido1->getItems().at(i);
        agregarElemento(item->getItem(), item->getCantidad(), item->getComentario(), ui->Comanda1);
    } */ // prueba antigua hardcodeando
}


cocinawindow::~cocinawindow()
{
    delete ui;
}
void cocinawindow::agregarMesa(int mesa, QListWidget *listWidget){
    
    QString mesaText = "Mesa " + QString::number(mesa);
    listWidget->addItem(mesaText);
    
}
void cocinawindow::agregarElemento(Item *item, int cantidad, const std::string &comentario, QListWidget *listWidget){
    
    QString itemText = QString::fromStdString(item->getNombre()) + " (x" + QString::number(cantidad) + ")" + " - Comentario: " + QString::fromStdString(comentario);
    listWidget->addItem(itemText);
}
void cocinawindow::on_pushButton_1_clicked()
{
    ui->Comanda1->clear();
}


void cocinawindow::on_pushButton_2_clicked()
{
    ui->Comanda_2->clear();
}


void cocinawindow::on_pushButton_3_clicked()
{
    ui->Comanda_3->clear();
}


void cocinawindow::on_pushButton_4_clicked()
{
    ui->Comanda_4->clear();
}

void cocinawindow::on_pushButton_5_clicked()
{
    ui->Comanda_5->clear();
}

void cocinawindow::on_pushButton_6_clicked()
{
    ui->Comanda_6->clear();
}

void cocinawindow::on_pushButton_7_clicked()
{
    ui->Comanda_7->clear();
}


void cocinawindow::on_pushButton_8_clicked()
{
    ui->Comanda_8->clear();
}

void cocinawindow::recibirPedido(Pedido* pedido)
{
    if (!pedido) return;
    
    std::vector<PedidoItem*> itemsComida;
    for (size_t i = 0; i < pedido->getItems().size(); i++) {
        PedidoItem* item = pedido->getItems().at(i);
        if (item->getItem()->getTipo() == "Comida") {
            itemsComida.push_back(item);
        }
    }
    
    if (itemsComida.empty()) {
        return;
    }
    
    QListWidget* comandaLibre = nullptr;
    
    if (ui->Comanda1->count() == 0) {
        comandaLibre = ui->Comanda1;
    } else if (ui->Comanda_2->count() == 0) {
        comandaLibre = ui->Comanda_2;
    } else if (ui->Comanda_3->count() == 0) {
        comandaLibre = ui->Comanda_3;
    } else if (ui->Comanda_4->count() == 0) {
        comandaLibre = ui->Comanda_4;
    } else if (ui->Comanda_5->count() == 0) {
        comandaLibre = ui->Comanda_5;
    } else if (ui->Comanda_6->count() == 0) {
        comandaLibre = ui->Comanda_6;
    } else if (ui->Comanda_7->count() == 0) {
        comandaLibre = ui->Comanda_7;
    } else if (ui->Comanda_8->count() == 0) {
        comandaLibre = ui->Comanda_8;
    }
    
    // sino a la primera nomaaa 
    if (!comandaLibre) {
        comandaLibre = ui->Comanda1;
        comandaLibre->clear();
    }
    
    //solo comida a cocina 
    agregarMesa(pedido->getMesa(), comandaLibre);
    for (PedidoItem* item : itemsComida) {
        agregarElemento(item->getItem(), item->getCantidad(), item->getComentario(), comandaLibre);
    }
}

