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

private:
    Ui::cocinawindow *ui;
};

#endif // COCINAWINDOW_H
