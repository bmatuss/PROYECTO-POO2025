#ifndef BARRAWINDOW_H
#define BARRAWINDOW_H

#include <QMainWindow>
#include <string>
#include <QListWidget>
#include "../models/pedido.h"
#include "../models/item.h"

namespace Ui {
class barrawindow;
}

class barrawindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit barrawindow(QWidget *parent = nullptr);
    ~barrawindow();
    
    void recibirPedido(Pedido* pedido);

private slots:
    void agregarElemento(Item *item, int cantidad, const std::string &comentario, QListWidget *listWidget);
    void agregarMesa(int mesa, QListWidget *listWidget);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::barrawindow *ui;
};

#endif // BARRAWINDOW_H
