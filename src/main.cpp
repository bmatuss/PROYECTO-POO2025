/**
 * @file main.cpp
 * @brief Entrada principal del programa
 * @date 2025
 */

#include "ui/poswindow.h"
#include "ui/cocinawindow.h"
#include "ui/barrawindow.h"

#include <QApplication>

/**
 * @brief Función principal
 * 
 * Crea las 3 ventanas del sistema (POS, cocina, bar) y las muestra.
 * 
 * @param argc Número de argumentos
 * @param argv Argumentos del programa
 * @return Código de salida
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    
    PosWindow posWindow;
    cocinawindow cocinaWindow;
    barrawindow barraWindow;
    
    // Conectar las ventanas
    posWindow.setCocinaWindow(&cocinaWindow);
    posWindow.setBarraWindow(&barraWindow);
    
    // Abrir las 3 ventanas simultáneamente
    posWindow.show();
    cocinaWindow.show();
    barraWindow.show();
    

    
    return a.exec();
}
