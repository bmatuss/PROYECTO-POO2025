#include "poswindow.h"
#include "ui_poswindow.h"

PosWindow::PosWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PosWindow)
{
    ui->setupUi(this);
}

PosWindow::~PosWindow()
{
    delete ui;
}
