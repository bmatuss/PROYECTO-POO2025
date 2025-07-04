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
