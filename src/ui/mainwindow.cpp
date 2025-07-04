#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , posWindow(nullptr)
{
    ui->setupUi(this);
    setWindowTitle("panel principal");
    abrirPOS();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::abrirPOS()
{
    if (!posWindow) {
        posWindow = new PosWindow(this);
    }
    posWindow->show();
}
