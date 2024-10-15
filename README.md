# so_long

## Descripción

El proyecto **so_long** es un videojuego desarrollado como parte del Common Core de 42 Network. He decidido utilizar la librería **MLX42**, una versión ligeramente modificada, mejorada y documentada de la MiniLibX. Esta biblioteca proporciona las funcionalidades necesarias para el desarrollo de gráficos en 2D.

## Requisitos

- **Librería**: MLX42

  [Repositorio de MLX42](https://github.com/42-Fundacion-Telefonica/MLX42/tree/master)
  
  [MiniLibX original](https://github.com/42Paris/minilibx-linux)

- **Sistema operativo**: Este proyecto fue desarrollado en **WSL 2** utilizando la distribución **Ubuntu 22.04**. No he probado el juego en otros sistemas operativos, ya que esta es la misma distribución utilizada en mi campus 42 Málaga.
Ten en cuenta que si vas a ejecutar este programa en WSL 2, usando como host principal Windows, debes de asegurarte de seguir los pasos de instalación de un Xserver para administrar la ventana del juego, como se especifica en la [instalación de MLX42 para Windows](https://github.com/42-Fundacion-Telefonica/MLX42/tree/master?tab=readme-ov-file#for-windows-with-windows-subsystem-for-linux-2-wsl2)
## Agradecimientos

Quiero expresar mi agradecimiento a **arommers** por su proyecto **so_long**, que utilicé como referencia y guía durante el desarrollo de este videojuego. Puedes consultar su proyecto aquí:  
[Repositorio de arommers](https://github.com/arommers/so_long/tree/master)

## Instalación

Para ejecutar el juego **so_long**, sigue estos pasos:

1. Clona el repositorio:
   ```bash
   git clone <URL_DEL_REPOSITORIO>
   cd so_long
   ```

2. Compila el proyecto:
   ```bash
   make
   ```

3. Ejecuta el juego con un mapa específico:
   ```bash
   ./so_long <map.ber>
   ```
   Asegúrate de sustituir `<map.ber>` por el nombre del mapa deseado. Los mapas están disponibles en la carpeta `maps/`.

## Notas

- Asegúrate de tener instaladas todas las dependencias necesarias para **MLX42** antes de compilar el proyecto.
- Puedes encontrar ejemplos de mapas dentro de la carpeta `maps/`.
- También puedes crear tu propio mapa siguiendo el formato correcto, donde:
  1. El mapa tiene que estar completamente rodeado por muros.
  2. Debe de haber como mínimo un objeto recolectable.
  3. Solo puede haber un jugador.
  4. Debe haber una única salida y que sea accesible, tanto la salida como el acceso a los elementos recolectables.
- Ten en cuenta que esto no pretende ser una guía didáctica del proyecto, únicamente quiero compartir mi proyecto publicamente en caso de que pueda ser de utilidad para alguien.
- La librería MLX42 tiene algunos leaks de memoria, propios de la librería los cuales no dependen del programa, sino de la gestión propia de la liberería (pasé bastante tiempo tratando de encontrar los leaks, hasta que descubrí esto xD)
- El uso de la librería MLX42 no está autorizado en todos los campus, normalmente la permitida es MiniLibX, por lo que antes de usarla asegúrate de que en tu campus está permitido el uso de la misma.
 
 ## Gameplay
  Aquí dejo un breve GIF mostrando brevemente el funcionamiento del juego:
  
![gameplay](https://github.com/user-attachments/assets/5ea54a2a-21d3-4523-b066-e1dbc15c715d)


