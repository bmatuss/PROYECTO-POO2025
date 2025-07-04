#include "barrawindow.h"
#include "ui_barrawindow.h"
#include <string>
#include "../models/bebida.h"


barrawindow::barrawindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::barrawindow)
{
    ui->setupUi(this);
    setWindowTitle("barra");
    Item *item1 = new Bebida("Cerveza", 500, false);
    Pedido *pedido1 = new Pedido(1); //ese 1 es el numero de mesa
    pedido1->agregarItem(item1, 2, "Sin hielo");
    pedido1->agregarItem(new Bebida("Vino", 700, false), 1, "Merlot");
    pedido1->agregarItem(new Bebida("Whisky", 1000, false), 1, "On the rocks");
    pedido1->agregarItem(new Bebida("Agua con gas", 300, true), 1, "Con hielo");
    pedido1->agregarItem(new Bebida("Piscola", 800, false), 3, "70 30");
    agregarMesa(pedido1->getMesa(), ui->listWidget_1);
    for (size_t i = 0; i < pedido1->getItems().size(); i++)
    {
        PedidoItem* item= pedido1->getItems().at(i); 
        agregarElemento(item->getItem(), item->getCantidad(), item->getComentario(), ui->listWidget_1);
    }
}


barrawindow::~barrawindow()
{
    delete ui;
}
void barrawindow::agregarMesa(int mesa, QListWidget *listWidget){
    
    QString mesaText = "Mesa " + QString::number(mesa);
    listWidget->addItem(mesaText);
    
}
void barrawindow::agregarElemento(Item *item, int cantidad, const std::string &comentario, QListWidget *listWidget){
    
    QString itemText = QString::fromStdString(item->getNombre()) + " (x" + QString::number(cantidad) + ")" + " - Comentario: " + QString::fromStdString(comentario);
    listWidget->addItem(itemText);
}

void barrawindow::on_pushButton_clicked()
{
    ui->listWidget_1->clear();
}


void barrawindow::on_pushButton_2_clicked()
{
    ui->listWidget_2->clear();
}


void barrawindow::on_pushButton_3_clicked()
{
    ui->listWidget_3->clear();
}


void barrawindow::on_pushButton_4_clicked()
{
    ui->listWidget_4->clear();
}


void barrawindow::on_pushButton_5_clicked()
{
    ui->listWidget_5->clear();
}


void barrawindow::on_pushButton_6_clicked()
{
    ui->listWidget_6->clear();
}


void barrawindow::on_pushButton_7_clicked()
{
    ui->listWidget_7->clear();
}


void barrawindow::on_pushButton_8_clicked()
{
    ui->listWidget_8->clear();
}

