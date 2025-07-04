/**
 * @file barrawindow.h
 * @brief Ventana para el módulo de bar
 * @date 2025
 */

#ifndef BARRAWINDOW_H
#define BARRAWINDOW_H

#include <QMainWindow>
#include <string>
#include <QListWidget>
#include "../models/pedido.h"
#include "../models/item.h"

namespace Ui {
class barrawindow;
}

/**
 * @brief Ventana del bar
 * 
 * Muestra comandas de bebidas que deben prepararse.
 * Especializada para cócteles y bebidas.
 */
class barrawindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la ventana de bar
     * @param parent Widget padre, por defecto nullptr
     * 
     * Inicializa la interfaz de usuario del bar, configura los
     * widgets necesarios y establece el título de la ventana.
     */
    explicit barrawindow(QWidget *parent = nullptr);
    
    /**
     * @brief Destructor de la ventana de bar
     * 
     * Libera la memoria utilizada por la interfaz de usuario.
     */
    ~barrawindow();
    
    /**
     * @brief Recibe y procesa un pedido para el bar
     * @param pedido Puntero al pedido que se debe mostrar en el bar
     * 
     * Este método toma un pedido completo y extrae únicamente los elementos
     * que requieren preparación en el bar, agregándolos a la comanda
     * correspondiente en la interfaz.
     * 
     * @note Solo se procesan los elementos de tipo Bebida que requieren
     * preparación en el bar.
     */
    void recibirPedido(Pedido* pedido);

private slots:
    /**
     * @brief Agrega un elemento del pedido a la lista visual
     * @param item Puntero al item del menú (bebida)
     * @param cantidad Cantidad solicitada del item
     * @param comentario Comentarios especiales del cliente (ej: "sin hielo", "70-30")
     * @param listWidget Widget donde se agregará el elemento
     * 
     * Formatea y muestra una bebida del pedido en la interfaz del bar
     * con toda la información necesaria para su preparación.
     */
    void agregarElemento(Item *item, int cantidad, const std::string &comentario, QListWidget *listWidget);
    
    /**
     * @brief Agrega una nueva mesa a la lista de comandas
     * @param mesa Número de la mesa
     * @param listWidget Widget de lista donde se mostrará la mesa
     * 
     * Crea una nueva entrada visual para identificar la mesa en la
     * interfaz del bar.
     */
    void agregarMesa(int mesa, QListWidget *listWidget);

    /**
     * @brief Slot para el primer botón de control del bar
     * 
     * Maneja las acciones relacionadas con la primera estación de trabajo del bar.
     */
    void on_pushButton_clicked();

    /**
     * @brief Slot para el segundo botón de control del bar
     * 
     * Maneja las acciones relacionadas con la segunda estación de trabajo del bar.
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Slot para el tercer botón de control del bar
     * 
     * Maneja las acciones relacionadas con la tercera estación de trabajo del bar.
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Slot para el cuarto botón de control del bar
     * 
     * Maneja las acciones relacionadas con la cuarta estación de trabajo del bar.
     */
    void on_pushButton_4_clicked();

    /**
     * @brief Slot para el quinto botón de control del bar
     * 
     * Maneja las acciones relacionadas con la quinta estación de trabajo del bar.
     */
    void on_pushButton_5_clicked();

    /**
     * @brief Slot para el sexto botón de control del bar
     * 
     * Maneja las acciones relacionadas con la sexta estación de trabajo del bar.
     */
    void on_pushButton_6_clicked();

    /**
     * @brief Slot para el séptimo botón de control del bar
     * 
     * Maneja las acciones relacionadas con la séptima estación de trabajo del bar.
     */
    void on_pushButton_7_clicked();

    /**
     * @brief Slot para el octavo botón de control del bar
     * 
     * Maneja las acciones relacionadas con la octava estación de trabajo del bar.
     */
    void on_pushButton_8_clicked();

private:
    /**
     * @brief Puntero a la interfaz de usuario generada por Qt Designer
     * 
     * Contiene todos los widgets y layouts definidos en el archivo .ui
     * correspondiente a la ventana del bar.
     */
    Ui::barrawindow *ui;
};

#endif // BARRAWINDOW_H
