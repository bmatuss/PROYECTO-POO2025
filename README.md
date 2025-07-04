# Sistema POS Restaurante

## Descripción

Sistema POS para restaurantes hecho en C++ con Qt. Maneja pedidos y coordina cocina, bar y caja.

## Funcionalidades

- **3 ventanas principales**:
  - POS: Para tomar pedidos
  - Cocina: Para ver comandas de comida  
  - Bar: Para ver comandas de bebidas

- Gestión de mesas y menú
- Pedidos con comentarios especiales
- Interfaz gráfica con Qt

## Estructura

**Clases principales:**
- `Item`: Base para elementos del menú
- `Pedido`: Maneja órdenes de mesas
- `PedidoItem`: Item individual en pedido
- `Categoria`: Organiza el menú

**Ventanas:**
- `PosWindow`: Ventana principal
- `CocinaWindow`: Para cocina
- `BarraWindow`: Para bar

## Compilación

**Con Make:**
```bash
make
```

**Con Qt Creator:**
1. Abrir Qt Creator
2. Abrir archivo `POS.pro`
3. Configurar kit si es necesario
4. Compilar con Ctrl+B (Cmd+B en macOS)

## Documentación

Para generar documentación:
```bash
doxygen Doxyfile
```

**Instalar Doxygen:**
- macOS: `brew install doxygen`
- Ubuntu: `sudo apt-get install doxygen`
- Windows: Descargar desde doxygen.nl

Ver docs en: `docs/html/index.html`

## Estructura

```
src/
├── main.cpp              # Entrada principal
├── models/               # Clases de datos
│   ├── item.h/.cpp      # Items del menú
│   ├── pedido.h/.cpp    # Pedidos
│   └── ...
└── ui/                  # Interfaces
    ├── poswindow.*      # Ventana principal
    ├── cocinawindow.*   # Ventana cocina
    └── barrawindow.*    # Ventana bar
```

## Autor

Diego Saavedra,Benjamin Matus,Abraham Garcia - PROYECTO-POO2025