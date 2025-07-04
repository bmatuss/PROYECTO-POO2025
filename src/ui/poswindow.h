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
};

#endif // POSWINDOW_H
