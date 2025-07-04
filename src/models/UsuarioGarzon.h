/**
 * @file UsuarioGarzon.h
 * @brief Definición de la clase UsuarioGarzon para empleados meseros
 * @date 2025
 */

#ifndef USUARIOGARZON_H
#define USUARIOGARZON_H
#include "Usuario.h"
#include <iostream>
#include <string>

/**
 * @brief Clase que representa a un garzón (mesero) del restaurante
 * 
 * Esta clase hereda de Usuario y representa a los empleados encargados
 * de tomar pedidos de los clientes y enviar comandas a la cocina.
 * Lleva un registro del total de comandas enviadas durante su turno.
 */
class UsuarioGarzon : public Usuario {
private:
    int total_comandas;  ///< Total de comandas enviadas por el garzón en el turno
    
public:
    /**
     * @brief Constructor de la clase UsuarioGarzon
     * @param id Identificador único del garzón
     * @param nombre Nombre completo del garzón
     */
    UsuarioGarzon(int id, const std::string& nombre)
        : Usuario(id, nombre), total_comandas(0) {};
        
    /**
     * @brief Envía una comanda a la cocina
     * 
     * Método para enviar una comanda a la cocina e incrementar
     * el contador de comandas totales del garzón.
     */
    void enviar_comanda();
    
    /**
     * @brief Obtiene el total de comandas enviadas
     * @return int Número total de comandas enviadas durante el turno
     */
    int getTotalComandas() const {
        return total_comandas;
    }
    
    /**
     * @brief Incrementa el contador de comandas
     */
    void incrementarComandas() {
        total_comandas++;
    }
    
    /**
     * @brief Reinicia el contador de comandas al inicio de un nuevo turno
     */
    void reiniciarContador() {
        total_comandas = 0;
    }
};

#endif // USUARIOGARZON_H