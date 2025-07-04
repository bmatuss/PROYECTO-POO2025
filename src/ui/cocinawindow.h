/**
 * @file cocinawindow.h
 * @brief Ventana para el módulo de cocina
 * @date 2025
 */

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

/**
 * @brief Ventana de cocina
 * 
 * Muestra comandas de comidas que deben prepararse.
 * Maneja múltiples comandas simultáneamente.
 */
class cocinawindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la ventana de cocina
     * @param parent Widget padre, por defecto nullptr
     * 
     * Inicializa la interfaz de usuario de la cocina, configura los
     * widgets necesarios y establece el título de la ventana.
     */
    explicit cocinawindow(QWidget *parent = nullptr);
    
    /**
     * @brief Destructor de la ventana de cocina
     * 
     * Libera la memoria utilizada por la interfaz de usuario.
     */
    ~cocinawindow();
    
    /**
     * @brief Recibe y procesa un pedido para la cocina
     * @param pedido Puntero al pedido que se debe mostrar en la cocina
     * 
     * Este método toma un pedido completo y extrae únicamente los elementos
     * que requieren preparación en cocina, agregándolos a la comanda
     * correspondiente en la interfaz.
     * 
     * @note Solo se procesan los elementos de tipo Comida que requieren
     * preparación en cocina.
     */
    void recibirPedido(Pedido* pedido);

private slots:
    /**
     * @brief Agrega una nueva mesa a la lista de comandas
     * @param mesa Número de la mesa
     * @param listWidget Widget de lista donde se mostrará la mesa
     * 
     * Crea una nueva entrada visual para identificar la mesa en la
     * interfaz de la cocina.
     */
    void agregarMesa(int mesa, QListWidget *listWidget);
    
    /**
     * @brief Agrega un elemento del pedido a la lista visual
     * @param item Puntero al item del menú
     * @param cantidad Cantidad solicitada del item
     * @param comentario Comentarios especiales del cliente
     * @param listWidget Widget donde se agregará el elemento
     * 
     * Formatea y muestra un elemento del pedido en la interfaz de cocina
     * con toda la información necesaria para su preparación.
     */
    void agregarElemento(Item *item, int cantidad, const std::string &comentario, QListWidget *listWidget);
    
    /**
     * @brief Slot para el botón de comanda 1
     * 
     * Maneja las acciones relacionadas con la primera comanda activa.
     */
    void on_pushButton_1_clicked();

    /**
     * @brief Slot para el botón de comanda 2
     * 
     * Maneja las acciones relacionadas con la segunda comanda activa.
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Slot para el botón de comanda 3
     * 
     * Maneja las acciones relacionadas con la tercera comanda activa.
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Slot para el botón de comanda 4
     * 
     * Maneja las acciones relacionadas con la cuarta comanda activa.
     */
    void on_pushButton_4_clicked();

    /**
     * @brief Slot para el botón de comanda 7
     * 
     * Maneja las acciones relacionadas con la séptima comanda activa.
     */
    void on_pushButton_7_clicked();

    /**
     * @brief Slot para el botón de comanda 5
     * 
     * Maneja las acciones relacionadas con la quinta comanda activa.
     */
    void on_pushButton_5_clicked();

    /**
     * @brief Slot para el botón de comanda 6
     * 
     * Maneja las acciones relacionadas con la sexta comanda activa.
     */
    void on_pushButton_6_clicked();

    /**
     * @brief Slot para el botón de comanda 8
     * 
     * Maneja las acciones relacionadas con la octava comanda activa.
     */
    void on_pushButton_8_clicked();

private:
    /**
     * @brief Puntero a la interfaz de usuario generada por Qt Designer
     * 
     * Contiene todos los widgets y layouts definidos en el archivo .ui
     * correspondiente a la ventana de cocina.
     */
    Ui::cocinawindow *ui;
};

#endif // COCINAWINDOW_H
