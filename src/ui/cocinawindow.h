#ifndef COCINAWINDOW_H
#define COCINAWINDOW_H

#include <QMainWindow>

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
