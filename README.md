# Sistema POS - Restaurante

## Descripción

Sistema de Punto de Venta (POS) para restaurantes desarrollado en C++ y Qt. El sistema permite gestionar pedidos, menús y coordinar entre diferentes áreas del restaurante (caja, cocina y bar).

## Características

- **Interfaz de Usuario Multi-ventana**: Tres interfaces especializadas para diferentes roles
  - **POS Window**: Interfaz principal para tomar pedidos
  - **Cocina Window**: Interfaz para la preparación de comidas
  - **Barra Window**: Interfaz para la preparación de bebidas

- **Gestión de Menú**: Sistema flexible para manejar diferentes tipos de items
- **Sistema de Pedidos**: Gestión completa de órdenes con comentarios especiales
- **Arquitectura Orientada a Objetos**: Código bien estructurado y mantenible

## Arquitectura

### Modelos Principales

- `Item`: Clase base abstracta para elementos del menú
- `Pedido`: Gestión de órdenes de las mesas
- `PedidoItem`: Items individuales dentro de un pedido
- `Categoria`: Clasificación de items del menú

### Interfaces de Usuario

- `PosWindow`: Ventana principal del sistema
- `CocinaWindow`: Interfaz para la cocina
- `BarraWindow`: Interfaz para la preparación de bebidas

## Compilación

### Opción 1: Usando Make
```bash
make
```

### Opción 2: Usando Qt Creator
1. Abrir Qt Creator
2. Seleccionar "Abrir Proyecto" o "Open Project"
3. Navegar hasta el directorio del proyecto
4. Seleccionar el archivo `POS.pro`
5. Configurar el kit de compilación (si es necesario)
6. Hacer clic en "Configurar Proyecto" o "Configure Project"
7. Compilar usando Ctrl+B (Cmd+B en macOS) o el botón de Build



## Documentación

La documentación del código se genera automáticamente usando Doxygen:

```bash
doxygen Doxyfile
```

### Instalación de Doxygen

Si no tienes Doxygen instalado:
- **macOS:** `brew install doxygen`
- **Ubuntu/Debian:** `sudo apt-get install doxygen`
- **Windows:** Descargar desde [doxygen.nl](http://www.doxygen.nl/download.html)

La documentación estará disponible en `docs/html/index.html`

## Estructura del Proyecto

```
src/
├── main.cpp              # Punto de entrada principal
├── models/               # Modelos de datos
│   ├── item.h/.cpp      # Clase base para items del menú
│   ├── pedido.h/.cpp    # Gestión de pedidos
│   └── ...
└── ui/                  # Interfaces de usuario
    ├── poswindow.h/.cpp # Ventana principal POS
    ├── cocinawindow.h/.cpp # Ventana de cocina
    └── barrawindow.h/.cpp  # Ventana de bar
```

## Autor

Tu Nombre - PROYECTO-POO2025