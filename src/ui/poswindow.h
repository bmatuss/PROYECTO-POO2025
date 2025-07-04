#ifndef POSWINDOW_H
#define POSWINDOW_H

#include <QMainWindow>

namespace Ui {
class PosWindow;
}

class PosWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PosWindow(QWidget *parent = nullptr);
    ~PosWindow();

private:
    Ui::PosWindow *ui;

private slots:
    void on_lineEdit_returnPressed();
    void crearBotonesMesas();
    void crearBotonesCategorias();
    void crearBotonesItems();
    void mesaSeleccionada();
    void itemSeleccionado();
    void categoriaSeleccionada();
};

#endif // POSWINDOW_H
