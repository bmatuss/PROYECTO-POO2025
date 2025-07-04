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

       ui->gridMesas->addWidget(boton, fila, columna);
    }
}
