#ifndef BARRAWINDOW_H
#define BARRAWINDOW_H

#include <QMainWindow>

namespace Ui {
class barrawindow;
}

class barrawindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit barrawindow(QWidget *parent = nullptr);
    ~barrawindow();

private:
    Ui::barrawindow *ui;
};

#endif // BARRAWINDOW_H
