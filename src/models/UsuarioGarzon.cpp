#include <iostream>
#include <string>
#include "UsuarioGarzon.h"
void UsuarioGarzon::enviar_comanda() {
    std::cout << "Enviando comanda del garzón: " << getNombre() << std::endl;
    total_comandas++;
    std::cout << "Total de comandas enviadas: " << getTotalComandas() << std::endl;
}