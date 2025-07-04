#ifndef COCINAWINDOW_H
#define COCINAWINDOW_H

#include <QMainWindow>
#include <string>
#include <QListWidget>
#include "../models/pedido.h"
#include "../models/item.h"

namespace Ui {
class cocinawindow;
}

class cocinawindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit cocinawindow(QWidget *parent = nullptr);
    ~cocinawindow();

private slots:
    void agregarMesa(int mesa, QListWidget *listWidget);
    void agregarElemento(Item *item, int cantidad, const std::string &comentario, QListWidget *listWidget);
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::cocinawindow *ui;
};

#endif // COCINAWINDOW_H
