/**
 * @file mesa.h
 * @brief Definición de la clase Mesa para gestionar mesas del restaurante
 * @date 2025
 */

#ifndef MESA_H
#define MESA_H

#include <vector>
#include <QString>
#include "pedido.h"

/**
 * @brief Enumeración para representar el estado de una mesa
 */
enum EstadoMesa {
    ABIERTA,    ///< Mesa disponible para recibir pedidos
    CERRADA     ///< Mesa cerrada, no acepta más pedidos
};

/**
 * @brief Clase que representa una mesa del restaurante
 * 
 * Esta clase gestiona una mesa física del restaurante, manteniendo
 * un registro de todos los pedidos realizados por los clientes
 * sentados en esa mesa y controlando su estado.
 */
class Mesa {
private:
    int numero;                        ///< Número identificador de la mesa
    EstadoMesa estado;                 ///< Estado actual de la mesa
    std::vector<Pedido*> pedidos;      ///< Lista de pedidos realizados en esta mesa

public:
    /**
     * @brief Constructor de la clase Mesa
     * @param numero Número identificador único de la mesa
     */
    Mesa(int numero) : numero(numero), estado(ABIERTA) {}

    /**
     * @brief Agrega un nuevo pedido a la mesa
     * @param pedido Puntero al pedido a agregar
     * @note Solo se pueden agregar pedidos si la mesa está abierta
     */
    void agregarPedido(Pedido* pedido) {
        if (estado == ABIERTA) {
            pedidos.push_back(pedido);
        }
    }

    /**
     * @brief Cierra la mesa para no recibir más pedidos
     */
    void cerrarMesa() {
        estado = CERRADA;
    }

    /**
     * @brief Verifica si la mesa está abierta
     * @return bool true si la mesa está abierta, false si está cerrada
     */
    bool estaAbierta() const {
        return estado == ABIERTA;
    }

    /**
     * @brief Obtiene la lista de pedidos de la mesa
     * @return const std::vector<Pedido*>& Referencia constante al vector de pedidos
     */
    const std::vector<Pedido*>& getPedidos() const {
        return pedidos;
    }

    /**
     * @brief Obtiene el número de la mesa
     * @return int Número identificador de la mesa
     */
    int getNumero() const {
        return numero;
    }

    /**
     * @brief Calcula el total de todos los pedidos de la mesa
     * @return double Monto total acumulado de todos los pedidos
     */
    double getTotalMesa() const {
        double total = 0.0;
        for (const Pedido* pedido : pedidos) {
            total += pedido->getMontoTotal();
        }
        return total;
    }
};

#endif // MESA_H
