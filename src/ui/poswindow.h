/**
 * @file poswindow.h
 * @brief Ventana principal del sistema POS
 * @date 2025
 */

#ifndef POSWINDOW_H
#define POSWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <QListWidget>
#include "../models/categoria.h"
#include "../models/pedido.h"
#include "../models/mesa.h"

// Forward declarations para evitar inclusiones circulares
class cocinawindow;
class barrawindow;

namespace Ui {
class PosWindow;
}

/**
 * @brief Ventana principal del POS
 * 
 * Permite tomar pedidos, manejar mesas y enviar órdenes
 * a cocina y bar.
 */
class PosWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor de la ventana POS
     * @param parent Widget padre (puede ser nullptr)
     */
    explicit PosWindow(QWidget *parent = nullptr);
    
    /**
     * @brief Destructor de la ventana POS
     */
    ~PosWindow();
    
    /**
     * @brief Establece la referencia a la ventana de cocina
     * @param cocina Puntero a la ventana de cocina para comunicación
     */
    void setCocinaWindow(cocinawindow* cocina);
    
    /**
     * @brief Establece la referencia a la ventana del bar
     * @param barra Puntero a la ventana del bar para comunicación
     */
    void setBarraWindow(barrawindow* barra);
    
    /**
     * @brief Busca una mesa específica por su número
     * @param numeroMesa Número identificador de la mesa
     * @return Mesa* Puntero a la mesa encontrada, nullptr si no existe
     */
    Mesa* buscarMesaPorNumero(int numeroMesa);

private:
    Ui::PosWindow *ui;                        ///< Interfaz de usuario generada por Qt Designer
    Categoria* categoriaActual;               ///< Categoría actualmente seleccionada
    Pedido* pedidoActual;                     ///< Pedido que se está construyendo
    cocinawindow* ventanaCocina;              ///< Referencia a la ventana de cocina
    barrawindow* ventanaBarra;                ///< Referencia a la ventana del bar
    std::vector<Mesa*> mesas;                 ///< Vector con todas las mesas del restaurante
    std::vector<QListWidget*> listasPedidos;  ///< Listas de pedidos por mesa

    /**
     * @brief Busca un item específico en la categoría actual
     * @param nombreItem Nombre del item a buscar
     * @return Item* Puntero al item encontrado, nullptr si no existe
     */
    Item* buscarItemEnCategoria(const std::string& nombreItem);

private slots:
    /**
     * @brief Slot activado cuando se presiona Enter en el campo de texto
     */
    void on_lineEdit_returnPressed();
    
    /**
     * @brief Slot para enviar pedido a cocina/bar
     */
    void on_enviarButton_clicked();
    
    /**
     * @brief Crea los botones dinámicos para las mesas
     */
    void crearBotonesMesas();
    
    /**
     * @brief Crea los botones dinámicos para las categorías del menú
     */
    void crearBotonesCategorias();
    
    /**
     * @brief Crea los botones dinámicos para los items de la categoría actual
     */
    void crearBotonesItems();
    
    /**
     * @brief Slot activado cuando se selecciona una mesa
     */
    void mesaSeleccionada();
    
    /**
     * @brief Slot activado cuando se selecciona un item del menú
     */
    void itemSeleccionado();
    
    /**
     * @brief Slot activado cuando se selecciona una categoría
     */
    void categoriaSeleccionada();
    
    /**
     * @brief Slot para procesar el pago de una mesa
     */
    void on_pagarButton_clicked();
};

#endif // POSWINDOW_H
