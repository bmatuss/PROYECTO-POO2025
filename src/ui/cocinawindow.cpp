#include "cocinawindow.h"
#include "ui_cocinawindow.h"

cocinawindow::cocinawindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cocinawindow)
{
    ui->setupUi(this);
    setWindowTitle("cocina");
}

cocinawindow::~cocinawindow()
{
    delete ui;
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

