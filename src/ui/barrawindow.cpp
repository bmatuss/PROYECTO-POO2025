#include "barrawindow.h"
#include "ui_barrawindow.h"

barrawindow::barrawindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::barrawindow)
{
    ui->setupUi(this);
    setWindowTitle("barra");
}

barrawindow::~barrawindow()
{
    delete ui;
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

