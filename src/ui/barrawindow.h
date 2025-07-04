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

private slots:
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
