/**
 * @file main.cpp
 * @brief Punto de entrada principal del Sistema POS
 * @date 2025
 */

#include "ui/poswindow.h"
#include "ui/cocinawindow.h"
#include "ui/barrawindow.h"

#include <QApplication>

/**
 * @brief Función principal del programa
 * 
 * Inicializa la aplicación Qt y crea las tres ventanas principales:
 * - POS Window: Interfaz principal para tomar pedidos
 * - Cocina Window: Interfaz para la cocina
 * - Barra Window: Interfaz para la preparación de bebidas
 * 
 * @param argc Número de argumentos de línea de comandos
 * @param argv Array de argumentos de línea de comandos
 * @return int Código de salida de la aplicación
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
