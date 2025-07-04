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
