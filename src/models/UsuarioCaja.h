/**
 * @file UsuarioCaja.h
 * @brief Definición de la clase UsuarioCaja para empleados de caja
 * @date 2025
 */

#ifndef USUARIOCAJA_H
#define USUARIOCAJA_H
#include <iostream>
#include <string>
#include "Usuario.h"

/**
 * @brief Clase que representa a un empleado de caja del restaurante
 * 
 * Esta clase hereda de Usuario y representa a los empleados encargados
 * de procesar los pagos y manejar las transacciones monetarias.
 * Lleva un registro del total recaudado durante su turno.
 */
class UsuarioCaja : public Usuario {
private:
    double total_recaudado = 0.0;  ///< Monto total recaudado durante el turno

public:
    /**
     * @brief Constructor de la clase UsuarioCaja
     * @param id Identificador único del empleado de caja
     * @param nombre Nombre completo del empleado
     */
    UsuarioCaja(int id, const std::string& nombre)
        : Usuario(id, nombre), total_recaudado(0.0) {}
        
    /**
     * @brief Procesa un pago de cliente
     * 
     * Método para procesar pagos y actualizar el total recaudado.
     * Implementa la lógica específica de procesamiento de pagos.
     */
    void procesarPago();
    
    /**
     * @brief Establece el total recaudado
     * @param total Monto total recaudado a establecer
     */
    void setTotalRecaudado(double total) {
        total_recaudado = total;
    }
    
    /**
     * @brief Obtiene el total recaudado durante el turno
     * @return double Monto total recaudado
     */
    double getTotalRecaudado() const {
        return total_recaudado;
    }
    
    /**
     * @brief Agrega un monto al total recaudado
     * @param monto Cantidad a agregar al total recaudado
     */
    void agregarRecaudacion(double monto) {
        total_recaudado += monto;
    }
};

#endif // USUARIOCAJA_H