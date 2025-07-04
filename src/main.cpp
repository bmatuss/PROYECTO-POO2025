#include "ui/poswindow.h"
#include "ui/cocinawindow.h"
#include "ui/barrawindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    
    PosWindow posWindow;
    cocinawindow cocinaWindow;
    barrawindow barraWindow;
    
    posWindow.setCocinaWindow(&cocinaWindow);
    posWindow.setBarraWindow(&barraWindow);
    
    //abrir las 3 ventnas de una pa
    posWindow.show();
    cocinaWindow.show();
    barraWindow.show();
    

    
    return a.exec();
}
